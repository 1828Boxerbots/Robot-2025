// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/PivotSubsystem.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"

PivotSubsystem::PivotSubsystem()
    : m_pivotSpark(PivotConstants::kPivotCanId, rev::spark::SparkMax::MotorType::kBrushless)
{
    m_pivotSpark.Configure(PivotConfig(),
                           rev::spark::SparkBase::ResetMode::kResetSafeParameters,
                           rev::spark::SparkBase::PersistMode::kPersistParameters);

    m_analogIn.SetAverageBits(8);
}

void PivotSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
  frc::SmartDashboard::PutBoolean("Pivot Left Safety", GetLeftSafety());
  frc::SmartDashboard::PutBoolean("Pivot Right Safety", GetRightSafety());
  frc::SmartDashboard::PutNumber("Pivot Pot", GetPot());
}

void PivotSubsystem::Set(double power)
{
    m_pivotSpark.Set(power);
}

bool PivotSubsystem::GetLeftSafety() const
{
    return !m_leftSafety.Get();
}

bool PivotSubsystem::GetRightSafety() const
{
    return !m_leftSafety.Get();
}

double PivotSubsystem::GetPot() const
{
    return m_Pot.Get();
}