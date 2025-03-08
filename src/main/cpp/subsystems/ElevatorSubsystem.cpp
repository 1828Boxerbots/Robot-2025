// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ElevatorSubsystem.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"

ElevatorSubsystem::ElevatorSubsystem()
    : m_elevatorSpark(ElevatorConstants::kelevatorCanId, rev::spark::SparkMax::MotorType::kBrushless)
{
    m_elevatorSpark.Configure(ElevatorConfig(),
                           rev::spark::SparkBase::ResetMode::kResetSafeParameters,
                           rev::spark::SparkBase::PersistMode::kPersistParameters);
}

void ElevatorSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
  frc::SmartDashboard::PutBoolean("Elevator Upper Safety", GetUpperSafety());
  frc::SmartDashboard::PutBoolean("Elevator Lower Safety", GetLowerSafety());
  frc::SmartDashboard::PutNumber("Elevator Height(in)", GetHeight());
}

void ElevatorSubsystem::Set(double power)
{
    m_elevatorSpark.Set(power);
}

bool ElevatorSubsystem::GetUpperSafety() const
{
    return !m_upperSafety.Get();
}

bool ElevatorSubsystem::GetLowerSafety() const
{
    return !m_lowerSafety.Get();
}

double ElevatorSubsystem::GetHeight() const
{
    return m_elvatorEncoder.GetPosition();
}