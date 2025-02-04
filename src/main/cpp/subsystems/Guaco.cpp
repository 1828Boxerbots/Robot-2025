#include "subsystems/Guaco.hpp"

namespace Robot2025
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

frc2::CommandPtr Guaco::Dispense(double speed)
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
                        m_guacoMotor.Set(speed);//Positive speed assuming same direction to push through and eject
                },
                //end
                [this] (bool interrupted)
                {
                        m_guacoMotor.Set(0);
                },
                //isfinished
                [this]
                {
                        return m_photodiode.GetVoltage() < GuacoConstants::kPhotodiodeThreshold;
                }
        );

frc2::CommandPtr Guaco::Load(double speed)
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
                        m_guacoMotor.Set(speed);//Positive speed assuming same direction to push through and eject
                },
                //end
                [this] (bool interrupted)
                {
                        m_guacoMotor.Set(0);
                },
                //isfinished
                [this]
                {
                        return m_photodiode.GetVoltage() >= GuacoConstants::kPhotodiodeThreshold;
                }
        );
}

}
