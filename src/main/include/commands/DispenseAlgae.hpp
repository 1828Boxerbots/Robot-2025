// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.



#pragma once
#include "Subsystems/Elevator.hpp"
#include "Subsystems/Shooter.hpp"
#include "Subsystems/Pivot.h"
#include "subsystems/Intake.hpp"


class DispenseAlgae
{

 public:
frc2::CommandPtr ShootBargeCmd();

frc2::CommandPtr ShootProcessorCmd();


  Robot2025::Pivot m_pivotSubsystem;
  Robot2025::Elevator m_elevatorSubsystem;
  Robot2025::Intake m_intake;
 



};
