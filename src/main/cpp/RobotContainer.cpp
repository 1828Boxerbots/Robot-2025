
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
#include <frc2/command/button/POVButton.h>
#include <units/angle.h>
#include <units/velocity.h>

#include <utility>

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
  // The left stick controls translation of the robot.
  // Turning is controlled by the X axis of the right stick.
  m_drive.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_drive.Drive(
            -units::meters_per_second_t{frc::ApplyDeadband(
                m_driverController.GetLeftY(), OIConstants::kDriveDeadband)},
            -units::meters_per_second_t{frc::ApplyDeadband(
                m_driverController.GetLeftX(), OIConstants::kDriveDeadband)},
            -units::radians_per_second_t{frc::ApplyDeadband(
                m_driverController.GetRightX(), OIConstants::kDriveDeadband)},
            true);
      },
      {&m_drive}));
}

void RobotContainer::ConfigureButtonBindings() {
  frc2::JoystickButton(&m_driverController,
                       frc::XboxController::Button::kRightBumper)
      .WhileTrue(new frc2::RunCommand([this] { m_drive.SetX(); }, {&m_drive}));

    // Coral Intake
    frc2::JoystickButton(&m_driverController, frc::XboxController::Button::kB).ToggleOnTrue(new frc2::FunctionalCommand(
        // Init
        [this] () {},
        // Execute
        [this] () {
            m_coral.Set(0.5);
        },
        // End
        [this] (bool interrupted) {
            m_coral.Set(0.0);
        },
        // Is Finished
        [this] () {
            return m_coral.GetPhotogate();
        },
        // Requirements
        {&m_coral}));

    // Coral Output
    frc2::JoystickButton(&m_driverController, frc::XboxController::Button::kA).ToggleOnTrue(new frc2::FunctionalCommand(
        // Init
        [this] () {},
        // Execute
        [this] () {
            m_coral.Set(0.5);
        },
        // End
        [this] (bool interrupted) {
            m_coral.Set(0.0);
        },
        // Is Finished
        [this] () {
            return !m_coral.GetPhotogate();
        },
        // Requirements
        {&m_coral}));

    // Algae Intake
    frc2::JoystickButton(&m_driverController, frc::XboxController::Button::kX).ToggleOnTrue(new frc2::FunctionalCommand(
        // Init
        [this] () {},
        // Execute
        [this] () {
            m_algae.Set(0.8);
        },
        // End
        [this] (bool interrupted) {
            m_algae.Set(0.0);
        },
        // Is Finished
        [this] () {
            return m_algae.GetLimitSwitch();
        },
        // Requirements
        {&m_algae}));

    // Algae Output
    frc2::JoystickButton(&m_driverController, frc::XboxController::Button::kY).ToggleOnTrue(new frc2::FunctionalCommand(
        // Init
        [this] () {},
        // Execute
        [this] () {
            m_algae.Set(-1.0);
        },
        // End
        [this] (bool interrupted) {
            m_algae.Set(0.0);
        },
        // Is Finished
        [this] () {
            return !m_algae.GetLimitSwitch();
        },
        // Requirements
        {&m_algae}));

    // Pivot Left
    frc2::POVButton(&m_driverController, 270, 0).WhileTrue(new frc2::FunctionalCommand(
        // Init
        [this] () {},
        // Execute
        [this] () {
            if (m_pivot.GetPot() >= 1730)
                m_pivot.Set(0.0);
            else
                m_pivot.Set(-0.25);
        },
        // End
        [this] (bool interrupted) {
            m_pivot.Set(0.0);
        },
        // Is Finished
        [this] () {
            return false;
        },
        // Requirements
        {&m_pivot}));

    // Pivot Right
    frc2::POVButton(&m_driverController, 90, 0).WhileTrue(new frc2::FunctionalCommand(
        // Init
        [this] () {},
        // Execute
        [this] () {
            if (m_pivot.GetPot() <= 1460)
                m_pivot.Set(0.0);
            else
                m_pivot.Set(0.25);
        },
        // End
        [this] (bool interrupted) {
            m_pivot.Set(0.0);
        },
        // Is Finished
        [this] () {
            return false;
        },
        // Requirements
        {&m_pivot}));

     // Elevator Up
    frc2::POVButton(&m_driverController, 0, 0).WhileTrue(new frc2::FunctionalCommand(
        // Init
        [this] () {},
        // Execute
        [this] () {
            if (m_elevator.GetHeight() <= -50.0)
                m_elevator.Set(0.0);
            else
                m_elevator.Set(-1.0);
        },
        // End
        [this] (bool interrupted) {
            m_elevator.Set(0.0);
        },
        // Is Finished
        [this] () {
            return false;
        },
        // Requirements
        {&m_elevator}));

    // Elevator Down
    frc2::POVButton(&m_driverController, 180, 0).WhileTrue(new frc2::FunctionalCommand(
        // Init
        [this] () {},
        // Execute
        [this] () {
            if (m_elevator.GetHeight() >= -1.0)
                m_elevator.Set(0.0);
            else
                m_elevator.Set(1.0);
        },
        // End
        [this] (bool interrupted) {
            m_elevator.Set(0.0);
        },
        // Is Finished
        [this] () {
            return false;
        },
        // Requirements
        {&m_elevator}));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // Set up config for trajectory
  frc::TrajectoryConfig config(AutoConstants::kMaxSpeed,
                               AutoConstants::kMaxAcceleration);
  // Add kinematics to ensure max speed is actually obeyed
  config.SetKinematics(m_drive.kDriveKinematics);

  // An example trajectory to follow.  All units in meters.
  auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
      // Start at the origin facing the +X direction
      frc::Pose2d{0_m, 0_m, 0_deg},
      // Pass through these two interior waypoints, making an 's' curve path
      {frc::Translation2d{1_m, 1_m}, frc::Translation2d{2_m, -1_m}},
      // End 3 meters straight ahead of where we started, facing forward
      frc::Pose2d{3_m, 0_m, 0_deg},
      // Pass the config
      config);

  frc::ProfiledPIDController<units::radians> thetaController{
      AutoConstants::kPThetaController, 0, 0,
      AutoConstants::kThetaControllerConstraints};

  thetaController.EnableContinuousInput(units::radian_t{-std::numbers::pi},
                                        units::radian_t{std::numbers::pi});

  frc2::SwerveControllerCommand<4> swerveControllerCommand(
      exampleTrajectory, [this]() { return m_drive.GetPose(); },

      m_drive.kDriveKinematics,

      frc::PIDController{AutoConstants::kPXController, 0, 0},
      frc::PIDController{AutoConstants::kPYController, 0, 0}, thetaController,

      [this](auto moduleStates) { m_drive.SetModuleStates(moduleStates); },

      {&m_drive});

  // Reset odometry to the starting pose of the trajectory.
  m_drive.ResetOdometry(exampleTrajectory.InitialPose());

  // no auto
  return frc2::SequentialCommandGroup(
      std::move(swerveControllerCommand),
      frc2::InstantCommand(
          [this]() { m_drive.Drive(0_mps, 0_mps, 0_rad_per_s, false); }, {})).ToPtr();
}
