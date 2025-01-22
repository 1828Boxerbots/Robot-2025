#include "subsystems/Guaco.h"

namespace Robo2025
{

Guaco::Guaco()
{
        //Guaco constructor
}


Guaco::~Guaco()
{
        //Guaco deconstructor
}



double Guaco::GetAngle()
{
//Checks the servo angle
  return m_guacoServo.GetAngle();
};

void Guaco::SetAngle(double angle)
{
//Sets the servo angle
  m_guacoServo.SetAngle(angle);
};

}
