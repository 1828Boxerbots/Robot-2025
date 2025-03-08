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

void Intake::Init()
{

}

void Intake::Periodic() 
{
        frc::SmartDashboard::PutNumber("Intake Motor", m_loadMotor1.Get());
        frc::SmartDashboard::PutBoolean("Intake Photogate", m_LimitSwitch.Get());
}


bool Intake::IsBallIn()
{
//Checks if the ball is in 
  if(m_LimitSwitch.Get() == true) //placeholder target voltage value, theoretically correct but check.
  {
        return true;
  }
  else
  {
        return false;
  }
};

frc2::FunctionalCommand Intake::
Load(double speed, Robot2025::Intake& intake)
{       
        return frc2::FunctionalCommand 
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
                        m_loadMotor1.Set(0); //0 for now, change later after team agreement so we dont burn out motors
                },
                //isfinished
                [this]
                {
                        return m_LimitSwitch.Get() != true; //placeholder ultrasonic value
                },
                {&intake}


        );
}

frc2::FunctionalCommand Intake::Dispense(double speed, Robot2025::Intake& intake)
{       
        return frc2::FunctionalCommand 
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
                        return m_LimitSwitch.Get() == true; //placeholder ultrasonic value
                },
                {&intake}
               
        );
}

}

