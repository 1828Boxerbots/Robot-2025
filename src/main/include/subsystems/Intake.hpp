#pragma once
#include <rev/SparkMax.h>
#include "Constants.h"
#include <frc/Encoder.h>
#include <frc/AnalogInput.h>

namespace Robo2025

{

class Intake
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
   void SetMotors(double speed);





private:

};

}