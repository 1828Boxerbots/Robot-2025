// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/controller/PIDController.h>
#include <frc/geometry/Translation2d.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/SwerveControllerCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <units/angle.h>
#include <units/velocity.h>

#include <utility>

#include "Constants.h"
#include "subsystems/DriveTrainSub.h"

using namespace DriveConstants;

RobotContainer::RobotContainer() 
{
  ConfigureBindings();
  m_DriveSub.SetDefaultCommand(frc2::RunCommand([this] {m_DriveSub.Drive(-units::meters_per_second_t{frc::ApplyDeadband(m_DriveController.GetLeftY(), OIConstants::kDriveDeadband)}, -units::meters_per_second_t{frc::ApplyDeadband(m_DriveController.GetLeftX(), OIConstants::kDriveDeadband)}, -units::radians_per_second_t{frc::ApplyDeadband(m_DriveController.GetRightX(), OIConstants::kDriveDeadband)}, true, true);}, {&m_DriveSub}));
}

void RobotContainer::ConfigureBindings()
{
  frc2::JoystickButton(&m_DriveController, frc::XboxController::Button::kRightBumper).WhileTrue(new frc2::RunCommand([this] {m_DriveSub.SetXShapeWheelFormation();}, {&m_DriveSub}));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {}
