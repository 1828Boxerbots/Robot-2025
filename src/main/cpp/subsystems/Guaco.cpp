#include "subsystems/Guaco.hpp"

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

double Guaco::GetPhotodiodeVoltage()
{
        return m_photodiode.GetVoltage();
}

bool Guaco::PhotodiodeThreshold()
{
        if(m_photodiode.GetVoltage() >= GuacoConstants::kPhotodiodeThreshold)
        {
                return true;
        }
        return false;
}

frc2::CommandPtr Guaco::SetMotorSpeed(double speed)
{       [this, speed]
        {
          m_guacoMotor.Set(speed);
        };
}

}
