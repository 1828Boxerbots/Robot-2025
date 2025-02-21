// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.hpp"
#include "subsystems/ExampleSubsystem.hpp"
#include "subsystems/DriveTrainSub.hpp"
#include "subsystems/Elevator.hpp"
#include "subsystems/Guaco.hpp"
#include "subsystems/Intake.hpp"
#include "subsystems/Pivot.hpp"
#include "subsystems/Camera.hpp"
#include "commands/DispenseAlgae.hpp"
#include "commands/DispenseCoralCmd.hpp"
#include "commands/LoadAlgaeCmd.hpp"
#include "commands/LoadCoralCmd.hpp"
#include <rev/SparkClosedLoopController.h>



/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic me thods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

  


 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController1{
      OIConstants::kDriverController1Port};
  frc2::CommandXboxController m_driverController2{
      OIConstants::kDriverController2Port};

  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;

 Robot2025::DriveSubsystem m_DriveSub;
 Robot2025::Elevator m_Elevator;
 Robot2025::Intake m_Intake;
 Robot2025::Guaco m_Guaco;
 Robot2025::Pivot m_Pivot;
 DispenseAlgae m_DispenseAlgaeCmd;
 DispenseCoralCmd m_DispenseCoralCmd; 
 LoadAlgaeCmd m_LoadAlgaeCmd;
 LoadCoralCmd m_LoadCoralCmd;


  void ConfigureBindings();
};
