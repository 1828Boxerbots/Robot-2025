// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.



#pragma once
#include "Subsystems/Elevator.hpp"
#include "Subsystems/Pivot.hpp"
#include "subsystems/Intake.hpp"


class DispenseAlgae
{

 public:
 DispenseAlgae();
  ~DispenseAlgae();
 


frc2::CommandPtr ShootAlgaeCmd(int Pivot, int Level);

  Robot2025::Pivot m_pivotSubsystem;
  Robot2025::Elevator m_elevatorSubsystem;
  Robot2025::Intake m_intakeSubsystem;
 



};
