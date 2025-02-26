#pragma once

#include <rev/SparkMax.h>
#include "Constants.hpp"
#include <frc/Encoder.h>
#include <frc/DigitalInput.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

namespace Robot2025

{

class Intake : public frc2::SubsystemBase
{
   public:

//Public Methods:

   Intake();
   ~Intake();
   void Init();
   void Periodic() override;


//Private member variables

rev::spark::SparkMax m_loadMotor1{IntakeConstants::kIntakeMotorPort1, rev::spark::SparkMax::MotorType::kBrushed};
frc::DigitalInput m_Photogate{IntakeConstants::kPhotogatePort}; 



//Private methods

/// @brief Checks if ball is in load, possibly using a photogate
/// @return bool
   bool IsBallIn();

/// @brief sets Shintake motors 
   frc2::CommandPtr Load(double speed);
   frc2::CommandPtr Dispense(double speed);

private:



private:

};

}