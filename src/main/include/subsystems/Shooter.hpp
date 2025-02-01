#pragma once

#include <rev/SparkMax.h>
#include "Constants.h"
#include <frc/Encoder.h>

namespace Robo2025
{
class Shooter
{

    public:

//Public Methods:

    Shooter();
    ~Shooter();

   

    


    private:

//Private Member varibles:


rev::spark::SparkMax m_ShooterMotor1{ShooterConstants::kShooterMotorPort1, rev::spark::SparkMax::MotorType::kBrushless};
rev::spark::SparkMax m_ShooterMotor2{ShooterConstants::kShooterMotorPort2, rev::spark::SparkMax::MotorType::kBrushless};


//Private Methods:

/// @brief Distance based shooter with equation used
/// @param speed 
void DynamicShoot(int speed);


};
}