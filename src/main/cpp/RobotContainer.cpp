// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.hpp"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.hpp"
#include "commands/ExampleCommand.hpp"
#include <frc/trajectory/constraint/SwerveDriveKinematicsConstraint.h>
#include "Constants.hpp"
#include "subsystems/DriveTrainSub.hpp"
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc2/command/SwerveControllerCommand.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc2/command/RunCommand.h>



RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here





  // m_DriveSub.SetDefaultCommand(frc2::RunCommand(
  //   [this] 
  //   {
  //     m_DriveSub.Drive
  //         (-units::meters_per_second_t {m_DriveSub.Clamp(frc::ApplyDeadband(
  //       m_driverController.GetLeftY(), OIConstants::kDriveDeadband), 0.1) },},

  //         -units::meters_per_second_t{frc::ApplyDeadband(
  //             m_driverController.GetLeftX(), OIConstants::kDriveDeadband)},

  //         -units::radians_per_second_t{frc::ApplyDeadband(
  //             m_driverController.GetRightX(), OIConstants::kDriveDeadband)},
  //         true)
  //         );
  //   },
  //   {&m_DriveSub}
  //   );

    m_DriveSub.SetDefaultCommand(frc2::RunCommand(
    [this] {
      m_DriveSub.Drive(
          -units::meters_per_second_t{frc::ApplyDeadband(
              m_driverController.GetLeftY(), OIConstants::kDriveDeadband)},
              
          -units::meters_per_second_t{frc::ApplyDeadband(
              m_driverController.GetLeftX(), OIConstants::kDriveDeadband)},
          -units::radians_per_second_t{frc::ApplyDeadband(
              m_driverController.GetRightX(), OIConstants::kDriveDeadband)},
          true);
    },
    {&m_DriveSub})
  );

//   // Configure the button bindings
 ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::AutosCmd(&m_subsystem);
}




