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


RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.

//Intake  load/dispense: x/y
  m_driverController.X().WhileTrue(m_Intake.Load(IntakeConstants::kSpeed));
  m_driverController.Y().WhileTrue(m_Intake.Dispense(GuacoConstants::kSpeed));

//GUaco load/dispense: A/B
  m_driverController.A().WhileTrue(m_Guaco.Load(GuacoConstants::kSpeed));
  m_driverController.B().WhileTrue(m_Guaco.Dispense(GuacoConstants::kSpeed));
 

 //Elevator up / down: dpad up / dpad down
m_driverController.POVUp().WhileTrue(m_Elevator.SetMotorValue(ElevatorConstants::kSpeed));
m_driverController.POVDown().WhileTrue(m_Elevator.SetMotorValue(-ElevatorConstants::kSpeed));

//Pov left/right: dpad left / dpad right
m_driverController.POVLeft().WhileTrue(m_Pivot.SetMotorManually(PivotConstants::kSpeed));
m_driverController.POVRight().WhileTrue(m_Pivot.SetMotorManually(-PivotConstants::kSpeed));


//Joysticks

 m_drivesub.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_drivesub.Drive(
            -units::meters_per_second_t{frc::ApplyDeadband(
                m_driverController.GetLeftY(), OIConstants::kDriveDeadband)},
            -units::meters_per_second_t{frc::ApplyDeadband(
                m_driverController.GetLeftX(), OIConstants::kDriveDeadband)},
            -units::radians_per_second_t{frc::ApplyDeadband(
                m_driverController.GetRightX(), OIConstants::kDriveDeadband)},
            true);
      },
      {&m_drivesub}));

      frc2::JoystickButton(&m_driverController,
                       frc::XboxController::Button::kRightBumper)
      .WhileTrue(new frc2::RunCommand([this] { m_drive.SetX(); }, {&m_drive}));
}



}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous

  // zTODO: Fill in parameters
  Robot2025::DriveSubsystem m_drivesub;
  Robot2025::Pivot m_Pivot;
  Robot2025::Elevator m_Elevator;
  Robot2025::Guaco m_Guaco;
  Robot2025::Intake m_Intake;
  Robot2025::Camera m_Camera;
  

  frc::SwerveDriveKinematicsConstraint<4> constraint(m_drivesub.kDriveKinematics, DriveConstants::kMaxSpeed);
  frc::TrajectoryConfig config{AutoConstants::kMaxSpeed,
                               AutoConstants::kMaxAcceleration};

  
   frc::ProfiledPIDController<units::radians>::Constraints ProfilePidconstraint;

  
   config.AddConstraint(constraint);
   config.SetKinematics(m_drivesub.kDriveKinematics); 

     auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
      // Start at the origin facing the +X direction
      frc::Pose2d{0_m, 0_m, 0_deg},
      // Pass through these two interior waypoints, making an 's' curve path
      {frc::Translation2d{1_m, 1_m}, frc::Translation2d{2_m, -1_m}},
      // End 3 meters straight ahead of where we started, facing forward
      frc::Pose2d{3_m, 0_m, 0_deg},
      // Pass the config
      config);

  frc::PIDController PIDx(0.04, 0, 0);
  frc::PIDController PIDy(0.04, 0, 0);
  frc::ProfiledPIDController <units::radians> PIDTheta(0.04, 0.0, 0.0, ProfilePidconstraint);

    
  frc2::SwerveControllerCommand<4> (exampleTrajectory, m_drivesub.GetPose(), m_drivesub.kDriveKinematics, m_drivesub.GetHeading(), )



  return autos::AutosCmd(&m_subsystem);
}
