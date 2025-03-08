// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/AlgaeSubsystem.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"

AlgaeSubsystem::AlgaeSubsystem()
    : m_AlgaeSpark(AlgaeConstants::kAlgaeCanId, rev::spark::SparkMax::MotorType::kBrushed)
{
    m_AlgaeSpark.Configure(AlgaeConfig(),
                           rev::spark::SparkBase::ResetMode::kResetSafeParameters,
                           rev::spark::SparkBase::PersistMode::kPersistParameters);
}

void AlgaeSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
  frc::SmartDashboard::PutBoolean("Algae Limit Switch", GetLimitSwitch());
}

void AlgaeSubsystem::Set(double power)
{
    m_AlgaeSpark.Set(power);
}

bool AlgaeSubsystem::GetLimitSwitch() const
{
    return !m_limitSwitch.Get();
}