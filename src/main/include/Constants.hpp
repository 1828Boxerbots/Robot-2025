// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/trajectory/TrapezoidProfile.h>
#include <rev/SparkMax.h>
#include <units/acceleration.h>
#include <units/angular_acceleration.h>
#include <units/angular_velocity.h>
#include <units/current.h>
#include <units/length.h>
#include <units/velocity.h>

#include <numbers>

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or bool constants.  This should not be used for any other purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {
// Driving Parameters - Note that these are not the maximum capable speeds of
// the robot, rather the allowed maximum speeds
constexpr units::meters_per_second_t kMaxSpeed = 4.8_mps;
constexpr units::radians_per_second_t kMaxAngularSpeed{2 * std::numbers::pi};

constexpr double kDirectionSlewRate = 1.2;   // radians per second
constexpr double kMagnitudeSlewRate = 1.8;   // percent per second (1 = 100%)
constexpr double kRotationalSlewRate = 2.0;  // percent per second (1 = 100%)

// Chassis configuration
constexpr units::meter_t kTrackWidth =
    0.686_m;  // Distance between centers of right and left wheels on robot
constexpr units::meter_t kWheelBase =
    0.686_m;  // Distance between centers of front and back wheels on robot

// Angular offsets of the modules relative to the chassis in radians
constexpr double kFrontLeftChassisAngularOffset = -std::numbers::pi / 2;
constexpr double kFrontRightChassisAngularOffset = 0;
constexpr double kRearLeftChassisAngularOffset = std::numbers::pi;
constexpr double kRearRightChassisAngularOffset = std::numbers::pi / 2;

// SPARK MAX CAN IDs
constexpr int kFrontLeftDrivingCanId = 9;
constexpr int kRearLeftDrivingCanId = 7;
constexpr int kFrontRightDrivingCanId = 1;
constexpr int kRearRightDrivingCanId = 3;

constexpr int kFrontLeftTurningCanId = 8;
constexpr int kRearLeftTurningCanId = 6;
constexpr int kFrontRightTurningCanId = 2;
constexpr int kRearRightTurningCanId = 4;

constexpr double MinDriveSpeed = 0;
constexpr double MinTurnSpeed = 0;


}  // namespace DriveConstants

namespace ModuleConstants {
// The MAXSwerve module can be configured with one of three pinion gears: 12T,
// 13T, or 14T. This changes the drive speed of the module (a pinion gear with
// more teeth will result in a robot that drives faster).
constexpr int kDrivingMotorPinionTeeth = 14;

// Calculations required for driving motor conversion factors and feed forward
constexpr double kDrivingMotorFreeSpeedRps =
    5676.0 / 60;  // NEO free speed is 5676 RPM
constexpr units::meter_t kWheelDiameter = 0.0762_m;
constexpr units::meter_t kWheelCircumference =
    kWheelDiameter * std::numbers::pi;
// 45 teeth on the wheel's bevel gear, 22 teeth on the first-stage spur gear, 15
// teeth on the bevel pinion
constexpr double kDrivingMotorReduction =
    (45.0 * 22) / (kDrivingMotorPinionTeeth * 15);
constexpr double kDriveWheelFreeSpeedRps =
    (kDrivingMotorFreeSpeedRps * kWheelCircumference.value()) /
    kDrivingMotorReduction;
}  // namespace ModuleConstants

namespace AutoConstants {
constexpr auto kMaxSpeed = 3_mps;
constexpr auto kMaxAcceleration = 3_mps_sq;
constexpr auto kMaxAngularSpeed = 3.142_rad_per_s;
constexpr auto kMaxAngularAcceleration = 3.142_rad_per_s_sq;

constexpr double kPXController = 0.5;
constexpr double kPYController = 0.5;
constexpr double kPThetaController = 0.5;

extern const frc::TrapezoidProfile<units::radians>::Constraints
    kThetaControllerConstraints;
}  // namespace AutoConstants

namespace OIConstants {
constexpr int kDriverControllerPort = 0;
constexpr double kDriveDeadband = 0.05;
}  // namespace OIConstants

namespace CameraConstants 
{

//Camera constants

}  // namespace OperatorConstants


namespace ClimbConstants 
{
    //Climbconstants
inline constexpr int kClimbMotorPort1 = 0;
inline constexpr int kClimbMotorPort2 = 0;


}  

namespace ElevatorConstants 
{
    //Elevator constants

inline constexpr int kElevatorMotorPort1 = 5;
inline constexpr int kHallEffectPortL1 = 0;
inline constexpr int kHallEffectPortL2 = 0;
inline constexpr int kHallEffectPortL3 = 0;
inline constexpr int kHallEffectPortL4 = 0;
inline constexpr int kEncoderPortA = 0;
inline constexpr int kEncoderPortB = 0;

inline constexpr int kL0 = 0;
inline constexpr int kL1 = 1;
inline constexpr int kL2= 2;
inline constexpr int kL3 = 3;
inline constexpr int kL4 = 4; 
inline constexpr int MaxElevatorHeight = 0; 




namespace ElevatorPID
{
    //Pids constants
    inline constexpr int kSetPoint = 0;
    inline constexpr int kPosition = 0;

    inline constexpr int kP = 0;
    inline constexpr int kI = 0;
    inline constexpr int kD = 0;
    inline constexpr int kMaxOutput = 0;
    inline constexpr int kMinOutput = 0;
    inline constexpr int kv = 0;
    inline constexpr int kMaxVelocity = 0;
    inline constexpr int kMaxAcceleration = 0;
    inline constexpr int kAllowedError = 0;
}

}  


namespace DriveConstants 
{
        //Drive constants

inline constexpr int kDriverControllerPort = 0;

}  

namespace IntakeConstants 
{
    //Intake constants
    inline constexpr int kIntakeMotorPort1 = 11;
    inline constexpr int kSpeed = 0;

    //placeholder port please change
    inline constexpr int kUltraSonicPort = 10;
    inline constexpr double kUltraSonicThreshHold = 0.01;
}  

namespace ShooterConstants 
{
    //Shooter constants
    
    inline constexpr int kShooterMotorPort1 = 0;
    inline constexpr int kShooterMotorPort2 = 0;
}  

namespace GuacoConstants
{
    //guaco constants 
  inline constexpr int kGuacoMotorPort = 12;
    inline constexpr int kPhotodiodePort = 1;
    inline constexpr int kPhotodiodeThreshold = 0;
    inline constexpr int kSpeed = 0.4;
    //placeholder speed

    //Placeholder port, change once known. 
}  

namespace PivotConstants
{
    //Pivot constants

    inline constexpr int kPivotMotorPort = 10; 
    //placeholder values, please change. 

    inline constexpr int kHalleffectPortCloseSafetyStop = 10;
    inline constexpr int kHalleffectPortFarSafetyStop = 11; 
    inline constexpr int kHalleffectPortCoral = 12; 
    inline constexpr int kHalleffectPortBarge = 13; 
    inline constexpr int kHalleffectPortBase = 14; 
    inline constexpr int kHalleffectPortGroundPickup = 15; 
    inline constexpr int kEncoderPortA = 16;
    inline constexpr int kEncoderPortB = 17; 
    //placeholder values, please change.

    inline constexpr int kEncoderStudCount = 2018;
    inline constexpr double kSpeed = 0.5;
    //placeholder values, please change.

    inline constexpr double kCloseSafetyStopAngle = -270;
    inline constexpr double kFarSafetyStopAngle = 270; 
    inline constexpr double kCoralAngle = 120; 
    inline constexpr double kCoralLoadAngle = 120;
    inline constexpr double kBargeAngle = 95; 
    inline constexpr double kProcessorAngle = 0; 
    inline constexpr double kBaseAngle = 180; 
    inline constexpr double kGroundPickupAngle = -40; 
    //placeholder values, please change. 

namespace PivotPIDConstants
{
    //ALL are placeholder values please calibrate
    inline constexpr int kSetPoint = 0;
    inline constexpr int kP = 0;
    inline constexpr int kI = 0;
    inline constexpr int kD = 0;
    inline constexpr int kMinOutput = 0;
    inline constexpr int kMaxOutput = 0;
    inline constexpr int kV = 0;
    inline constexpr int kMaxVel = 0;
    inline constexpr int kMaxAccel = 0;
    inline constexpr int kAllowedErr = 0;
}

} 

namespace DriverConstants
{
    inline constexpr int kDriverControllerPort = 0;
}
