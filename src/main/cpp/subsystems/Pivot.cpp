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

void Pivot::Init()
{

}

void Pivot::Periodic() 
{
  frc::SmartDashboard::PutNumber("Pivot Motor", m_pivotMotor.Get());
  frc::SmartDashboard::PutNumber("Pivot Encoder Velocity", m_encoder.GetVelocity());
  frc::SmartDashboard::PutNumber("Pivot Encoder Count Revolved", m_encoder.GetPosition());
  frc::SmartDashboard::PutBoolean("Pivot Halleffect Left Safetystop", m_halleffectLeftSafetyStop.Get());
  frc::SmartDashboard::PutBoolean("Pivot Halleffect Right Safetystop", m_halleffectRightSafetyStop.Get());
  //frc::SmartDashboard::PutBoolean("Pivot Halleffect Barge", m_halleffectBarge.Get());
  //frc::SmartDashboard::PutBoolean("Pivot Halleffect Base", m_halleffectBase.Get());
  //frc::SmartDashboard::PutBoolean("Pivot Halleffect Coral", m_halleffectCoral.Get());
  //frc::SmartDashboard::PutBoolean("Pivot Halleffect Ground Pickup", m_halleffectGroundPickup.Get());
}



// bool Pivot::AtAngleBarge()
// {
// //Checks if at Barge angle halleffect
//   return m_halleffectBarge.Get();
// }; 

// bool Pivot::AtAngleBase()
// {
// //Checks if at Base angle halleffect
//   return m_halleffectBase.Get();
// };

// bool Pivot::AtAngleCoral()
// {
// //Checks if at Coral angle halleffect
//   return m_halleffectCoral.Get();
// };

// bool Pivot::AtAngleGroundPickup()
// {
// //Checks if at high angle halleffect
//   return m_halleffectGroundPickup.Get();
// }; 

bool Pivot::AtAngleLeftSafetyStop()
{
//Checks if at base angle halleffect
  return m_halleffectLeftSafetyStop.Get();
};

bool Pivot::AtAngleRightSafetyStop()
{
//Checks if at low angle halleffect
  return m_halleffectRightSafetyStop.Get();
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
         double targetDist = (angle * (PivotConstants::kEncoderStudCount/360)); //Fraction was previously the reciprocal, double check conversion factor. 
         m_PivotPIDController.SetReference(targetDist, rev::spark::SparkBase::ControlType::kPosition);
      },
      //End
      [this] (bool interrupted)
      {
        m_pivotMotor.Set(0); //Stops motor so PIDS doesn't possibly continue endlessly (PLEASE CHECK THIS KNOWLEDGE)
      },
      //Is Finished
      [this, angle]
      {
        //Checks if at safety stop through either detection from halleffect or potentiometer, then must also be attempting to continue that way to cut command. 
        if (((m_halleffectLeftSafetyStop.Get() == true) || (m_potentiometer.Get() <= PivotConstants::kLeftSafetyStopAngle)) && (m_pivotMotor.Get() < 0))
        {
          return true; 
        }
        else if (((m_halleffectRightSafetyStop.Get() == true) || (m_potentiometer.Get() >= PivotConstants::kRightSafetyStopAngle)) && (m_pivotMotor.Get() > 0))
        {
          return true; 
        }

        return false;
      }
    );
}; 

double Pivot::GetEncoder()
{
    return m_encoder.GetPosition();
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
  frc2::StartEndCommand
  (
    //execute
    [this,speed] 
    {
      if (((m_halleffectLeftSafetyStop.Get() == true) || (m_potentiometer.Get() <= PivotConstants::kLeftSafetyStopAngle)) && (speed < 0))
        {
          m_pivotMotor.Set(0); //Stops motor
        }
        else if (((m_halleffectRightSafetyStop.Get() == true) || (m_potentiometer.Get() >= PivotConstants::kRightSafetyStopAngle)) && (speed > 0))
        {
          m_pivotMotor.Set(0); //Stops motor
        }
        else
        {
          m_pivotMotor.Set(speed);
        }
    },
    //end
    [this]
    {
      m_pivotMotor.Set(0);
    }
  );
}


};

