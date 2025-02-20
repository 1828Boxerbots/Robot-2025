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

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
//Four main buttons 
//Note: these are sequential, meaning one happens AFTER the other. Would be better if did both at same time but thats for later

  m_driverController.Y().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kBargeAngle)).AndThen(std::move(m_Intake.Dispense(IntakeConstants::kSpeed))));  //Algae Barg sequence: Moves pivot to barg shoot pos. + shoots Algae
  m_driverController.X().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kReef1Angle)).AndThen(std::move(m_Elevator.MoveL2())).AndThen(std::move(m_Intake.Load(IntakeConstants::kSpeed)))); //Algae Reef 1 sequence: Moves pivot to reef pos. + moves Elevator to L2 + loads algae
  m_driverController.B().OnTrue //Algae Reef 2 sequence: Moves pivot to reef pos. + moves Elevator to L3 + loads algae
  m_driverController.A().OnTrue //Algae floor sequence: MovesPivot to Algae floor pos. + LoadsAlgae
  
 
//Dpad

  m_driverController.POVUp().OnTrue   //Place Coral on L3 seq.: Move Elevator (L3) + MovePivot(coral pos)
  m_driverController.POVDown().OnTrue //Place Coral on L1 seq.: Move Elevator (L1) + MovePivot(coral pos)
  m_driverController.POVLeft().OnTrue //Place Coral on L2 seq.: Move Elevator (L2) + MovePivot(coral pos)
  m_driverController.POVRight().OnTrue //Palce Coral on L4 seq.: Move Elevator (L4) + MovePivot(coral pos)

  //Drive break: right bumper
  m_driverController.RightBumper().WhileTrue(
          new frc2::RunCommand([this] {
            m_DriveSub.SetX();
          }, {&m_DriveSub}));
  
  //Drive 

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // // An example command will be run in autonomous

  // // zTODO: Fill in parameters
  // Robot2025::DriveSubsystem m_drivesub;
  // Robot2025::Pivot m_Pivot;
  // Robot2025::Elevator m_Elevator;
  // Robot2025::Guaco m_Guaco;
  // Robot2025::Intake m_Intake;
  // Robot2025::Camera m_Camera;
  

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
