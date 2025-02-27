#include "subsystems/Intake.hpp"

namespace Robot2025
{

Intake::Intake()
{
        //Intake constructor
}


Intake::~Intake()
{
        //Intake deconstructor
}


bool Intake::IsBallIn()
{
//Checks if the ball is in 
  if(m_ultraSonic.GetVoltage() <= 0.01) //placeholder target voltage value, theoretically correct but check.
  {
        return true;
  }
  else
  {
        return false;
  }
};

frc2::CommandPtr Intake::Load(double speed)
{       
        frc2::FunctionalCommand 
        (
                //init 
                [this]
                {

                },
                //execute
                [this, speed]
                {
                        m_loadMotor1.Set(speed); //Positive speed assuming Positive = push in
                },
                //end
                [this] (bool interrupted)
                {
                        m_loadMotor1.Set(0);
                },
                //isfinished
                [this]
                {
                        return m_ultraSonic.GetVoltage() <= IntakeConstants::kUltraSonicThreshHold; //placeholder ultrasonic value
                }
        );
}

frc2::CommandPtr Intake::Dispense(double speed)
{       
        frc2::FunctionalCommand 
        (
                //init 
                [this]
                {

                },
                //execute
                [this, speed]
                {
                        m_loadMotor1.Set(-speed); //Negative speed assuming Positive = push in
                },
                //end
                [this] (bool interrupted)
                {
                        m_loadMotor1.Set(0);
                },
                //isfinished
                [this]
                {
                        return m_ultraSonic.GetVoltage() > IntakeConstants::kUltraSonicThreshHold; //placeholder ultrasonic value
                }
        );
}

}

