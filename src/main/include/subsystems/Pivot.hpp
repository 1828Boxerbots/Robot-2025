#pragma once
#include <rev/SparkMax.h>
#include "Constants.hpp"
#include <frc/Encoder.h>
#include <frc/DigitalOutput.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/FunctionalCommand.h>

namespace Robot2025

{

class Pivot : public frc2::SubsystemBase
{
   public:

//Public Methods:

   Pivot();
   ~Pivot();




   

//Private member variables

rev::spark::SparkMax m_pivotMotor{PivotConstants::kPivotMotorPort, rev::spark::SparkMax::MotorType::kBrushless};

rev::spark::SparkClosedLoopController m_PivotPIDController = m_pivotMotor.GetClosedLoopController();


frc::DigitalOutput m_halleffectBarge{PivotConstants::kHalleffectPortBarge};
frc::DigitalOutput m_halleffectBase{PivotConstants::kHalleffectPortBase};
frc::DigitalOutput m_halleffectCoral{PivotConstants::kHalleffectPortCoral};
frc::DigitalOutput m_halleffectGroundPickup{PivotConstants::kHalleffectPortGroundPickup};
frc::DigitalOutput m_halleffectCloseSafetyStop{PivotConstants::kHalleffectPortCloseSafetyStop};
frc::DigitalOutput m_halleffectFarSafetyStop{PivotConstants::kHalleffectPortFarSafetyStop};
//Low? LOW TAPER FAAADDDDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
frc::Encoder m_encoder{PivotConstants::kEncoderPortA, PivotConstants::kEncoderPortB};




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
   bool AtAngleCloseSafetyStop();

   /// @brief Checks halleffect sensor for FarSafetyStop angle 
/// @return bool
   bool AtAngleFarSafetyStop();
   
   

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