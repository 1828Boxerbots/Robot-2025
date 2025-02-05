#include "subsystems/Pivot.hpp"

namespace Robot2025
{

Pivot::Pivot()
{
        //Pivot constructor
        rev::spark::SparkBaseConfig config;
        config.closedLoop
    .P(PivotConstants::PivotPIDConstants::kP)
    .I(PivotConstants::PivotPIDConstants::kI)
    .D(PivotConstants::PivotPIDConstants::kD)
    .OutputRange(PivotConstants::PivotPIDConstants::kMinOutput, PivotConstants::PivotPIDConstants::kMaxOutput)
    .VelocityFF(1/PivotConstants::PivotPIDConstants::kV);
 
 config.closedLoop.maxMotion
    .MaxVelocity(PivotConstants::PivotPIDConstants::kMaxVel)
    .MaxAcceleration(PivotConstants::PivotPIDConstants::kMaxAccel)
    .AllowedClosedLoopError(PivotConstants::PivotPIDConstants::kAllowedErr);

     m_PivotPIDController.SetReference(PivotConstants::PivotPIDConstants::kSetPoint, rev::spark::SparkBase::ControlType::kPosition);
};



Pivot::~Pivot()
{
        //Pivot deconstructor
};



bool Pivot::AtAngleBarge()
{
//Checks if at Barge angle halleffect
  return m_halleffectBarge.Get();
}; 

bool Pivot::AtAngleBase()
{
//Checks if at Base angle halleffect
  return m_halleffectBase.Get();
};

bool Pivot::AtAngleCoral()
{
//Checks if at Coral angle halleffect
  return m_halleffectCoral.Get();
};

bool Pivot::AtAngleGroundPickup()
{
//Checks if at high angle halleffect
  return m_halleffectGroundPickup.Get();
}; 

bool Pivot::AtAngleCloseSafetyStop()
{
//Checks if at base angle halleffect
  return m_halleffectCloseSafetyStop.Get();
};

bool Pivot::AtAngleFarSafetyStop()
{
//Checks if at low angle halleffect
  return m_halleffectFarSafetyStop.Get();
};




frc2::CommandPtr Pivot::SetAngle(double angle)
{
    //Converts passed angle to move the motor the equivalent distance measured by the encoder. 
    return this->RunOnce
    (
      [this,angle] 
      {
         double targetDist = (angle * (360/PivotConstants::kEncoderStudCount)); 
         double currentDist = m_encoder.Get();
         if (currentDist < targetDist)
         {
           m_pivotMotor.Set(PivotConstants::kSpeed);
         }    
         else if (currentDist > targetDist)
         {
           m_pivotMotor.Set(-PivotConstants::kSpeed); 
         }
      }
    );

 
}; 

double Pivot::GetEncoder()
{
    return m_encoder.Get();
};

frc2::CommandPtr Pivot::StopMotor()
{
  return this->RunOnce
  (
    [this] 
    {
      m_pivotMotor.Set(0);
    }
  );
}

frc2::CommandPtr Pivot::SetMotorManually(double speed)
{
  return this->RunOnce
  (
    [this,speed]
    {
      m_pivotMotor.Set(speed);
    }
  );
}


};

