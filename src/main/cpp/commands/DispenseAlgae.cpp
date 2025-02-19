// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DispenseAlgae.hpp"

DispenseAlgae::DispenseAlgae()
{

}

DispenseAlgae::~DispenseAlgae()
{
    
}


frc2::CommandPtr DispenseAlgae::ShootAlgaeCmd(int Pivot, int Level)
{
std::move(m_pivotSubsystem.SetAngle(Pivot)).AndThen(std::move(m_elevatorSubsystem.MoveLevel(Level)));
}


