#pragma once
#include <rev/SparkMax.h>
#include "Constants.hpp"
#include <frc/Encoder.h>
#include <frc/DigitalInput.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/StartEndCommand.h>
#include <frc/AnalogPotentiometer.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <rev/SparkRelativeEncoder.h>

namespace Robot2025

{

class Pivot : public frc2::SubsystemBase
{
   public:

//Public Methods:

   Pivot();
   ~Pivot();

   void Init();
   void Periodic() override;

//Private member variables

rev::spark::SparkMax m_pivotMotor{PivotConstants::kPivotMotorPort, rev::spark::SparkMax::MotorType::kBrushless};

rev::spark::SparkClosedLoopController m_PivotPIDController = m_pivotMotor.GetClosedLoopController();


//frc::DigitalInput m_halleffectBarge{PivotConstants::kHalleffectPortBarge};
//frc::DigitalInput m_halleffectBase{PivotConstants::kHalleffectPortBase};
//frc::DigitalInput m_halleffectCoral{PivotConstants::kHalleffectPortCoral};
//frc::DigitalInput m_halleffectGroundPickup{PivotConstants::kHalleffectPortGroundPickup};
frc::DigitalInput m_halleffectLeftSafetyStop{PivotConstants::kHalleffectPortLeftSafetyStop};
frc::DigitalInput m_halleffectRightSafetyStop{PivotConstants::kHalleffectPortRightSafetyStop};
frc::AnalogPotentiometer m_potentiometer {PivotConstants::kPotentiometerPort};
//Low? LOW TAPER FAAADDDDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
rev::spark::SparkRelativeEncoder m_encoder = m_pivotMotor.GetEncoder();

//Private methods

/// @brief Checks halleffect sensor for Barge angle 
/// @return bool
   bool AtAngleBarge();

   /// @brief Checks halleffect sensor for Base angle 
/// @return bool
   bool AtAngleBase();

   /// @brief Checks halleffect sensor for Coral angle 
/// @return bool
   bool AtAngleCoral();

/// @brief Checks halleffect sensor for GroundPickup angle 
/// @return bool
   bool AtAngleGroundPickup();

   /// @brief Checks halleffect sensor for CloseSafetyStop angle 
/// @return bool
   bool AtAngleLeftSafetyStop();

   /// @brief Checks halleffect sensor for FarSafetyStop angle 
/// @return bool
   bool AtAngleRightSafetyStop();

   /// @brief Checks encoder value 
   double GetEncoder();

/// @brief Moves the pivot motor to wanted angle 
   frc2::CommandPtr SetAngle(double angle);
// Stops Motor
   frc2::CommandPtr StopMotor();
// Sets Motor manually to specified speed
   frc2::CommandPtr SetMotorManually(double speed);

   private:

};

}