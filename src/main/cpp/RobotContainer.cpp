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
              m_driverController1.GetLeftY(), OIConstants::kDriveDeadband)},
          -units::meters_per_second_t{frc::ApplyDeadband(
              m_driverController1.GetLeftX(), OIConstants::kDriveDeadband)},
          -units::radians_per_second_t{frc::ApplyDeadband(
              m_driverController1.GetRightX(), OIConstants::kDriveDeadband)},
          true);
    },
    {&m_DriveSub})
  );

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  //Note: MOST of these are sequential, meaning one happens AFTER the other
  //Note: Could be better to do all at same time by using .AlongWith and not .AndThen

//Algae: A B X Y LeftBumper (Controller1)

  //A - Algae floor: moves Pivot (Algae Floor) + moves Elevator (L1)
  m_driverController1.A().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kGroundPickupAngle))
    .AndThen(std::move(m_Elevator.MoveLevel(ElevatorConstants::kL1))));

  //B - Algae Reef 2: moves Pivot (Algae Reef2)+ moves Elevator (L3)
  m_driverController1.B().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kReef2Angle))
    .AndThen(std::move(m_Elevator.MoveLevel(ElevatorConstants::kL3))));

  //X - Algae Reef 1: moves Pivot (Algae Reef1) + moves Elevator (L2)
  m_driverController1.X().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kReef1Angle))
    .AndThen(std::move(m_Elevator.MoveLevel(ElevatorConstants::kL2))));

  //Y - Algae Barge: moves Pivot (Barge) + moves Elevator (L4)
  m_driverController1.Y().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kBargeAngle))
    .AndThen(std::move(m_Elevator.MoveLevel(ElevatorConstants::kL4)))); 

  //LeftBumper - Algae PickUp: moves Pivot (Floor) + moves Elevator (L2?)
  m_driverController1.LeftBumper().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kGroundPickupAngle))
    .AndThen(std::move(m_Elevator.MoveLevel(ElevatorConstants::kL2))));//   !Elevaor pos. is a placeholder!


//Coral: D-pad LeftTrigger (Controller1)

  //Down - Coral L1: move Pivot (Coral) + move Elevator (L1)
  m_driverController1.POVDown().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kCoralAngle))
    .AndThen(std::move(m_Elevator.MoveLevel(ElevatorConstants::kL1))));

  //Left - Coral L2: move Pivot (Coral) + move Elevator (L2)
  m_driverController1.POVLeft().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kCoralAngle))
    .AndThen(std::move(m_Elevator.MoveLevel(ElevatorConstants::kL2))));

  //Up - Coral L3: move Pivot (Coral) + move Elevator (L3)
  m_driverController1.POVUp().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kCoralAngle))
    .AndThen(std::move(m_Elevator.MoveLevel(ElevatorConstants::kL3))));

  //Right - Coral L4: move Pivot (Coral) + move Elevator (L4)
  m_driverController1.POVRight().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kCoralAngle))
    .AndThen(std::move(m_Elevator.MoveLevel(ElevatorConstants::kL4)))); 

  //LeftTrigger - Coral load: move Pivot (Coral) + move Elevator (L2?)
  m_driverController1.LeftTrigger().OnTrue(std::move(m_Pivot.SetAngle(PivotConstants::kCoralLoadAngle))
    .AndThen(std::move(m_Elevator.MoveLevel(ElevatorConstants::kL2))));//   !Elevaor pos. is a placeholder!


//Dispense/Load GameElement: A B LeftTrigger RightTrigger (Controller2)

  //A - Coral load: run Guaco (Load)
  m_driverController2.A().OnTrue(std::move(m_Guaco.Load(GuacoConstants::kSpeed)));

  //B - Algae load: run Intake (Load)
  m_driverController2.A().OnTrue(std::move(m_Intake.Load(IntakeConstants::kSpeed)));

  //LeftTrigger - Coral dispense: run Guaco (dispense)
  m_driverController2.LeftTrigger().WhileTrue(std::move(m_Guaco.Dispense(GuacoConstants::kSpeed)));

  //RightTrigger - Algae dispense: run Intake (dispense)
  m_driverController2.RightTrigger().WhileTrue(std::move(m_Intake.Dispense(IntakeConstants::kSpeed)));


//Drivetain Break: RightBumper (Controller1)

  //RightBumper - Break: set Drive (X)
  m_driverController1.RightBumper().WhileTrue(new frc2::RunCommand([this] {
    m_DriveSub.SetX();
  }, {&m_DriveSub}));
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
