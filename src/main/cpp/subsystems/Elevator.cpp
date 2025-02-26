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

 Elevator::~Elevator()
 {
    // NOTE: Currently does nothing
 }

void Elevator::Init()
{

}

void Elevator::Periodic() 
{
  frc::SmartDashboard::PutBoolean("Elevator Halleffect L1", m_HallEffectL1.Get());
  frc::SmartDashboard::PutBoolean("Elevator Halleffect L2", m_HallEffectL2.Get());
  frc::SmartDashboard::PutBoolean("Elevator Halleffect L3", m_HallEffectL3.Get());
  frc::SmartDashboard::PutBoolean("Elevator Halleffect L4", m_HallEffectL4.Get());
  frc::SmartDashboard::PutNumber("Elevator Encoder Distance", m_ElevatorEncoder.GetPosition());
  frc::SmartDashboard::PutNumber("Elevator Encoderd Speed", m_ElevatorEncoder.GetVelocity());
  frc::SmartDashboard::PutNumber("Elevator Motor", m_ElevatorMotor1.Get());
}
 
 frc2::CommandPtr Elevator::MoveLevel(int level)
 {
     switch (level)
     {
         case ElevatorConstants::kL0: 
         return this->RunOnce
    (
      [this] 
      {
        m_controller.SetReference(ElevatorConstants::kL0, rev::spark::SparkBase::ControlType::kPosition);
      }
     ); 

         case ElevatorConstants::kL1:
         return this->RunOnce
    (
      [this] 
      {
        m_controller.SetReference(ElevatorConstants::kL1, rev::spark::SparkBase::ControlType::kPosition);
      }
     ); 

         case ElevatorConstants::kL2:
         return this->RunOnce
    (
      [this] 
      {
        m_controller.SetReference(ElevatorConstants::kL2, rev::spark::SparkBase::ControlType::kPosition);
      }
     ); 

         case ElevatorConstants::kL3:
         return this->RunOnce
    (
      [this] 
      {
        m_controller.SetReference(ElevatorConstants::kL3, rev::spark::SparkBase::ControlType::kPosition);
      }
     ); 

         case ElevatorConstants::kL4:
         return this->RunOnce
    (
      [this] 
      {
        m_controller.SetReference(ElevatorConstants::kL4, rev::spark::SparkBase::ControlType::kPosition);
      }
     ); 
         
         break;
     }
 };


frc2::CommandPtr Elevator::MoveL2()
{
   return this->RunOnce
    (
      [this] 
      {
        m_controller.SetReference(ElevatorConstants::kL2, rev::spark::SparkBase::ControlType::kPosition);
      }
     ); 
};

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

<<<<<<< Updated upstream
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
=======
int Elevator::GetEncoder()
{
   return m_ElevatorEncoder.GetPosition();
>>>>>>> Stashed changes
    
  );

  };

  int Elevator::GetEncoderValue()
  {
     return m_ElevatorEncoder.Get();
  };

};