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


frc2::CommandPtr Elevator::MoveL3()
{
   return this->RunOnce
    (
      [this] 
      {
       m_controller.SetReference(ElevatorConstants::kL3, rev::spark::SparkBase::ControlType::kPosition);
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

frc2::CommandPtr Elevator::SetMotorValue(int value)
{
   [value, this]
   {
   m_ElevatorMotor1.Set(value);
   };

};

int Elevator::GetEncoderValue()
{
   return m_ElevatorEncoder.Get();
   
};

};