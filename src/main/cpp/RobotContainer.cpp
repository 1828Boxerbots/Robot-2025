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
  //Initialize all of your commands and subsystems here
  m_DriveSub.SetDefaultCommand(frc2::RunCommand(
    [this] {
      m_DriveSub.Drive(
          -units::meters_per_second_t{m_DriveSub.Clamp(frc::ApplyDeadband(
              m_driverController.GetLeftY(), OIConstants::kDriveDeadband, 0.1), 0.1, m_Elevator)},
              
          -units::meters_per_second_t{m_DriveSub.Clamp(frc::ApplyDeadband(
              m_driverController.GetLeftX(), OIConstants::kDriveDeadband), 0.1, m_Elevator)},

          -units::radians_per_second_t{m_DriveSub.Clamp(frc::ApplyDeadband(
              m_driverController.GetRightX(), OIConstants::kDriveDeadband), 0.1, m_Elevator)},
          true);
    },
    {&m_DriveSub})
);
  
  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{

  // Intake load/dispense: X / Y
  m_driverController.X().OnTrue(frc2::CommandPtr(m_Intake.Load(IntakeConstants::kSpeed, m_Intake)));
  m_driverController.Y().OnTrue(frc2::CommandPtr(m_Intake.Dispense(IntakeConstants::kSpeed, m_Intake)));

  //Guaco load/dispense: A / B
  m_driverController.A().OnTrue(frc2::CommandPtr(m_Guaco.Load(GuacoConstants::kSpeed, m_Guaco)));
  m_driverController.B().OnTrue(frc2::CommandPtr(m_Guaco.Dispense(GuacoConstants::kSpeed, m_Guaco)));
 
  //Elevator up/down: dpad up / dpad down
  //m_driverController.POVUp().OnTrue(frc2::CommandPtr(m_Elevator.SetMotorValue(ElevatorConstants::kSpeed, m_Elevator)));
  //m_driverController.POVUp().OnTrue(frc2::CommandPtr(m_Elevator.SetMotorValue(ElevatorConstants::kSpeed, m_Elevator)));

  //Pivot left/right: dpad left / dpad right
  //m_driverController.POVRight().OnTure(frc2::CommandPtr(m_Pivot.SetMotorManually(PivotConstants::kSpeed, m_Pivot)));
  //m_driverController.POVLeft().OnTure(frc2::CommandPtr(m_Pivot.SetMotorManually(-PivotConstants::kSpeed, m_Pivot)));

  //Drive break: right bumper
  m_driverController.RightBumper().WhileTrue(
          new frc2::RunCommand([this] {
            m_DriveSub.SetX();
          }, {&m_DriveSub}));
  
  // // Drive 

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // // An example command will be run in autonomous

  // zTODO: Fill in parameters
  // // Robot2025::DriveSubsystem m_drivesub;
  // // Robot2025::Pivot m_Pivot;
  // // Robot2025::Elevator m_Elevator;
  // // Robot2025::Guaco m_Guaco;
  // // Robot2025::Intake m_Intake;
  // // Robot2025::Camera m_Camera;
  

  // frc::SwerveDriveKinematicsConstraint<4> constraint(m_drivesub.kDriveKinematics, DriveConstants::kMaxSpeed);
  // frc::TrajectoryConfig config{AutoConstants::kMaxSpeed,
  //                              AutoConstants::kMaxAcceleration};

  
  //  frc::ProfiledPIDController<units::radians>::Constraints ProfilePidconstraint;

  
  //  config.AddConstraint(constraint);
  //  config.SetKinematics(m_drivesub.kDriveKinematics); 

  //    auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
  //     // Start at the origin facing the +X direction
  //     frc::Pose2d{0_m, 0_m, 0_deg},
  //     // Pass through these two interior waypoints, making an 's' curve path
  //     {frc::Translation2d{1_m, 1_m}, frc::Translation2d{2_m, -1_m}},
  //     // End 3 meters straight ahead of where we started, facing forward
  //     frc::Pose2d{3_m, 0_m, 0_deg},
  //     // Pass the config
  //     config);

  // frc::PIDController PIDx(0.04, 0, 0);
  // frc::PIDController PIDy(0.04, 0, 0);
  // frc::ProfiledPIDController <units::radians> PIDTheta(0.04, 0.0, 0.0, ProfilePidconstraint);

    
  // frc2::SwerveControllerCommand<4> (exampleTrajectory, m_drivesub.GetPose(), m_drivesub.kDriveKinematics, m_drivesub.GetHeading(), )
  return autos::AutosCmd(&m_subsystem);
}




