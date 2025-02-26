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

void Guaco::Init()
{

}

void Guaco::Periodic() 
{
        frc::SmartDashboard::PutNumber("Guaco Motor", m_guacoMotor.Get());
        frc::SmartDashboard::PutBoolean("Guaco Photodiode Voltage", m_photogate.Get());
}

double Guaco::GetPhotogate()
{
        return m_photogate.Get();
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
                        m_guacoMotor.Set(speed); //Positive speed assuming same direction to push through and eject
                },
                //end
                [this] (bool interrupted)
                {
                        m_guacoMotor.Set(0);
                },
                //isfinished
                [this]
                {
                        return m_photogate.Get() != true;
                }
        );
}

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
                        m_guacoMotor.Set(speed); //Positive speed assuming same direction to push through and eject
                },
                //end
                [this] (bool interrupted)
                {
                        m_guacoMotor.Set(0);
                },
                //isfinished
                [this]
                {
                        return m_photogate.Get() == true;
                }
        );
}

}
