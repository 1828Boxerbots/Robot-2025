#pragma once

#include <rev/SparkMax.h>
#include "Constants.h"
#include <frc/Encoder.h>
#include <frc/AnalogInput.h>

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

namespace Robo2025

{

class Intake : public frc2::SubsystemBase
{
   public:

//Public Methods:

   Intake();
   ~Intake();




   

//Private member variables

rev::spark::SparkMax m_loadMotor1{IntakeConstants::kIntakeMotorPort1, rev::spark::SparkMax::MotorType::kBrushless};
rev::spark::SparkMax m_loadMotor2{IntakeConstants::kIntakeMotorPort2, rev::spark::SparkMax::MotorType::kBrushless};
frc::AnalogInput m_ultraSonic{IntakeConstants::kUltraSonicPort}; 



//Private methods

/// @brief Checks if ball is in load, possibly using a photogate
/// @return bool
   bool IsBallIn();

/// @brief sets Shintake motors 
   frc2::CommandPtr SetMotors(double speed);

private:



private:

};

}