// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DispenseAlgae.hpp"

DispenseAlgae::DispenseAlgae() = default;
<<<<<<< Updated upstream


frc2::CommandPtr DispenseAlgae::ShootProcessorCmd()
{
std::move(m_pivotSubsystem.SetAngle(PivotConstants::kProcessorAngle)).AndThen(std::move(m_elevatorSubsystem.MoveLevel(ElevatorConstants::kL0))).AndThen(std::move(m_intake));
}

frc2::CommandPtr DispenseAlgae::ShootBargeCmd()
{
std::move(m_pivotSubsystem.SetAngle(PivotConstants::kBargeAngle)).AndThen(std::move(m_elevatorSubsystem.MoveLevel())).AndThen(std::move(m_guacoSubsystem.Dispense(GuacoConstants::kSpeed)));
}
=======
>>>>>>> Stashed changes
