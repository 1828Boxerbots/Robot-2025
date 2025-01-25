#include "subsystems/Elevator.hpp"

namespace Robot2025
{
 Elevator::Elevator()
 {
    // NOTE: Currently does nothing
    
    m_controller.SetReference(ElevatorConstants::ElevatorPID::kSetPoint, rev::spark::SparkBase::ControlType::kPosition);
  
   // rev::spark::SparkMaxConfig config{};
 }

 Elevator::~Elevator()
 {
    // NOTE: Currently does nothing
 }

 
 void Elevator::MoveL1()
 {
   
 };


void Elevator::MoveL2()
{
   
};


void Elevator::MoveL3()
{
   
};


void Elevator::MoveL4()
{
   
};

int Elevator::GetHallEffectL1()
{
   int value = m_HallEffectL1.Get();
   return value;
}
   

int Elevator::GetHallEffectL2()
{
   int value = m_HallEffectL2.Get();
   return value;
};

int Elevator::GetHallEffectL3()
{
   int value = m_HallEffectL3.Get();
   return value;
};

int Elevator::GetHallEffectL4()
{
   int value = m_HallEffectL4.Get();
   return value;
};

int Elevator::GetMotorValue()
{
   return m_ElevatorMotor1.Get();
};

void Elevator::SetMotorValue(int value)
{
   m_ElevatorMotor1.Set(value);
};

int Elevator::GetEncoderValue()
{
   return m_ElevatorEncoder.Get();
   
};

};