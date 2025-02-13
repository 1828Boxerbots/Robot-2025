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
    frc2::FunctionalCommand 
    (  
      //init
      [this]
      {

      },
      //execute
      [this,angle] 
      {
         double targetDist = (angle * (360/PivotConstants::kEncoderStudCount)); 
         m_PivotPIDController.SetReference(targetDist, rev::spark::SparkBase::ControlType::kPosition);
      },
      //End
      [this] (bool interrupted)
      {

      },
      //Is Finished
      [this]
      {
        if ((m_halleffectCloseSafetyStop.Get() == true) or (m_halleffectFarSafetyStop.Get() == true))
        {
          m_pivotMotor.Set(0); //Stops motor, could not stop if PIDS make it keep going. 
          return true;
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
  frc2::FunctionalCommand
  (
    //init
    [this]
    {

    },
    //execute
    [this,speed]
    {
      m_pivotMotor.Set(speed);
    },
    //End
    [this] (bool isinterrupted)
    {

    },
    //Isfinished
    [this]
    {
      if ((m_halleffectCloseSafetyStop.Get() == true) or (m_halleffectFarSafetyStop.Get() == true))
        {
          m_pivotMotor.Set(0); //Stops motor, could not stop if PIDS make it keep going. 
          return true;
        }
        return true;
    }
  );
}


};

