#include "subsystems/Elevator.hpp"
 
namespace Robot2025
{
 Elevator::Elevator()
 {
    // NOTE: Currently does nothing
    
    m_controller.SetReference(ElevatorConstants::ElevatorPID::kSetPoint, rev::spark::SparkBase::ControlType::kPosition);
    m_ElevatorMotor1.SetInverted(true);


   rev::spark::SparkBaseConfig config{};
   config.closedLoop
   .P(ElevatorConstants::ElevatorPID::kP)
   .I(ElevatorConstants::ElevatorPID::kI)
   .D(ElevatorConstants::ElevatorPID::kD)
   .OutputRange(ElevatorConstants::ElevatorPID::kMinOutput, ElevatorConstants::ElevatorPID::kMaxOutput);

      m_controller.SetReference(ElevatorConstants::ElevatorPID::kSetPoint, rev::spark::SparkBase::ControlType::kPosition);

     rev::spark::SparkBaseConfig config{};
     config.closedLoop
     .P(ElevatorConstants::ElevatorPID::kP)
     .I(ElevatorConstants::ElevatorPID::kI)
     .D(ElevatorConstants::ElevatorPID::kD)
     .OutputRange(ElevatorConstants::ElevatorPID::kMinOutput, ElevatorConstants::ElevatorPID::kMaxOutput);

     config.closedLoop.VelocityFF(1/ElevatorConstants::ElevatorPID::kv);

     config.closedLoop.maxMotion
     .MaxVelocity(ElevatorConstants::ElevatorPID::kMaxVelocity)
     .MaxAcceleration(ElevatorConstants::ElevatorPID::kMaxAcceleration)
     .AllowedClosedLoopError(ElevatorConstants::ElevatorPID::kAllowedError);


   }

   Elevator::~Elevator()
   {
      // NOTE: Currently does nothing
   }

  
   frc2::CommandPtr Elevator::MoveLevel(int level)
   {
       //Converts passed angle to move the motor the equivalent distance measured by the encoder. 
      frc2::FunctionalCommand
      (  
        //init
        [this]
        {

        },
        //execute
        [this,level] 
        {
           m_controller.SetReference(level, rev::spark::SparkBase::ControlType::kPosition);
        },
        //End
        [this] (bool interrupted)
        {
          m_ElevatorMotor1.Set(0); //Stops motor, could not stop if PIDS make it keep going. 
        },
        //Is Finished
        [this, level]
        {
          //Checks if at safety stop through either detection from halleffect or potentiometer, then must also be attempting to continue that way to cut command. 
          if (((m_HallEffectL1.Get() == true) || (m_ElevatorEncoder.Get() <= ElevatorConstants::kL1)) && (m_ElevatorMotor1.Get() < 0))
          {
            return true; 
          }
          else if (((m_HallEffectL4.Get() == true) || (m_ElevatorEncoder.Get() >= ElevatorConstants::kL4)) && (m_ElevatorMotor1.Get() > 0))
          {
            return true; 
          }
          else if((m_ElevatorEncoder.Get() > (level - 30)) && (m_ElevatorEncoder.Get() < (level + 30)))
          {
            return true; 
          }
          return false;

        }
      );

  };


  frc2::CommandPtr Elevator::MoveL4()
  {
        return this->RunOnce
      (
        [this] 
        {
          m_controller.SetReference(ElevatorConstants::kL4, rev::spark::SparkBase::ControlType::kPosition);
        }
       ); 
  
  };

  bool Elevator::GetHallEffectL1()
  {

     return m_HallEffectL1.Get();
  }


  bool Elevator::GetHallEffectL2()
  {

     return m_HallEffectL2.Get();
  };

  bool Elevator::GetHallEffectL3()
  {

     return m_HallEffectL3.Get();
  };

  bool Elevator::GetHallEffectL4()
  {

     return  m_HallEffectL4.Get();;
  };

  int Elevator::GetMotorValue()
  {
     return m_ElevatorMotor1.Get();
  };

  frc2::CommandPtr Elevator::SetMotorValue(double speed)
  {

    frc2::StartEndCommand
  (
    //execute
    [this,speed] 
    {
      if (((m_HallEffectL1.Get() == true) || (m_ElevatorEncoder.Get() <= ElevatorConstants::kL1)) && (m_ElevatorMotor1.Get() < 0))
          {
            m_ElevatorMotor1.Set(0);
          }
          else if (((m_HallEffectL4.Get() == true) || (m_ElevatorEncoder.Get() >= ElevatorConstants::kL4)) && (m_ElevatorMotor1.Get() > 0))
          {
            m_ElevatorMotor1.Set(0);
          }
          else
          {
            m_ElevatorMotor1.Set(speed);
          }
    },
    //end
    [this]
    {
      m_ElevatorMotor1.Set(0);
    }
    
  );

  };

  int Elevator::GetEncoderValue()
  {
     return m_ElevatorEncoder.Get();

  };

};