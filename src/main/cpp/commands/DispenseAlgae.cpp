// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DispenseAlgae.hpp"

DispenseAlgae::DispenseAlgae(Robot2025::Pivot& p, Robot2025::Elevator& e, Robot2025::Intake& i)
{
    m_pivotSubsystem = &p;
    m_elevatorSubsystem = &e;
    m_intakeSubsystem = &i;
}

DispenseAlgae::~DispenseAlgae()
{
    
}


// frc2::CommandPtr DispenseAlgae::ShootAlgaeCmd(int Pivot, int Level)
// {
//     if ((m_pivotSubsystem != nullptr) and (m_elevatorSubsystem != nullptr) and (m_intakeSubsystem != nullptr))
//     {
//         std::move(m_pivotSubsystem->SetAngle(Pivot)).AndThen(std::move(m_elevatorSubsystem->MoveLevel(Level))).AndThen(std::move(m_intakeSubsystem->Dispense(IntakeConstants::kSpeed)));
//     }

// }



