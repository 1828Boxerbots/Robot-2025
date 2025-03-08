// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/CoralSubsystem.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"

CoralSubsystem::CoralSubsystem()
    : m_coralSpark(CoralConstants::kCoralCanId, rev::spark::SparkMax::MotorType::kBrushed)
{
    m_coralSpark.Configure(CoralConfig(),
                           rev::spark::SparkBase::ResetMode::kResetSafeParameters,
                           rev::spark::SparkBase::PersistMode::kPersistParameters);
}

void CoralSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
  frc::SmartDashboard::PutBoolean("Coral Photogate", GetPhotogate());
}

void CoralSubsystem::Set(double power)
{
    m_coralSpark.Set(power);
}

bool CoralSubsystem::GetPhotogate() const
{
    return !m_photogate.Get();
}