#include "subsystems/Intake.hpp"

namespace Robo2025
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


frc2::CommandPtr Intake::SetMotors(double speed)
{
   return this->RunOnce
   (
      [this, speed] 
      {
            m_loadMotor1.Set(speed); 
            m_loadMotor2.Set(speed);
      }
   );

};

}