// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/trajectory/TrapezoidProfile.h>
#include <rev/SparkMax.h>
#include <units/acceleration.h>
#include <units/angular_acceleration.h>
#include <units/angular_velocity.h>
#include <units/current.h>
#include <units/length.h>
#include <units/velocity.h>
#include <numbers>


// Note: VALUES SHOULD BE CHANGED
namespace ModuleConstants
{
    constexpr bool kTurnEncoderInverted = true;
    constexpr int kDriveMotorPinionTeeth = 14;
    constexpr double kDriveMotorFreeSpeedRps = 5676.0 / 60;  // NEO free speed is 5676 RPM

    constexpr units::meter_t kWheelDiameter = 0.0762_m;
    constexpr units::meter_t kWheelCircumference = kWheelDiameter * std::numbers::pi;

    constexpr double kDriveMotorReduction = (45.0 * 22) / (kDriveMotorPinionTeeth * 15);
    constexpr double kDriveWheelFreeSpeedRps = (kDriveMotorFreeSpeedRps * kWheelCircumference.value()) / kDriveMotorReduction;

    constexpr double kDriveEncoderPosFactor = (kWheelDiameter.value() * std::numbers::pi) / kDriveMotorReduction;  // meters
    constexpr double kDriveEncoderVelFactor = ((kWheelDiameter.value() * std::numbers::pi) / kDriveMotorReduction) / 60.0;  // meters per second

    constexpr double kTurnEncoderPosFactor = (2 * std::numbers::pi);  // radians
    constexpr double kTurnEncoderVelFactor = (2 * std::numbers::pi) / 60.0;  // radians per second

    constexpr units::radian_t kTurnEncoderPosPIDInputMin = 0_rad;
    constexpr units::radian_t kTurnEncoderPosPIDInputMax = units::radian_t{kTurnEncoderPosFactor};

    constexpr double kDriveP = 0.04;
    constexpr double kDriveI = 0;
    constexpr double kDriveD = 0;
    constexpr double kDriveFF = (1 / kDriveWheelFreeSpeedRps);

    constexpr double kDriveOutputMin = -1;
    constexpr double kDriveOutputMax = 1;

    constexpr double kTurnP = 1;
    constexpr double kTurnI = 0;
    constexpr double kTurnD = 0;
    constexpr double kTurnFF = 0;

    constexpr double kTurnOutputMin = -1;
    constexpr double kTurnOutputMax = 1;

    constexpr rev::CANSparkMax::IdleMode kDriveMotorIdleMode = rev::CANSparkMax::IdleMode::kBrake;
    constexpr rev::CANSparkMax::IdleMode kTurnMotorIdleMode = rev::CANSparkMax::IdleMode::kBrake;

    constexpr units::ampere_t kDriveMotorCurrentLimit = 50_A;
    constexpr units::ampere_t kTurnMotorCurrentLimit = 20_A;
}

// Note: VALUES SHOULD BE CHANGED
namespace DriveConstants
{
    constexpr units::meters_per_second_t kMaxSpeed = 1.5_mps;
    constexpr units::radians_per_second_t kMaxAngularSpeed{2 * std::numbers::pi};

    constexpr double kDirectionSlewRate = 1.2;   // radians per second
    constexpr double kMagnitudeSlewRate = 1.8;   // percent per second (1 = 100%)
    constexpr double kRotationalSlewRate = 2.0;  // percent per second (1 = 100%)

    constexpr units::meter_t kTrackWidth = 0.6985_m;  // Distance between centers of right and left wheels on robot
    constexpr units::meter_t kWheelBase = 0.6985_m;  // Distance between centers of front and back wheels on robot

    constexpr double kFrontLeftChassisAngularOffset = -std::numbers::pi / 2;
    constexpr double kFrontRightChassisAngularOffset = 0;
    constexpr double kBackLeftChassisAngularOffset = std::numbers::pi;
    constexpr double kBackRightChassisAngularOffset = std::numbers::pi / 2;

    constexpr int kFrontLeftDriveCANID = 6;
    constexpr int kFrontRightDriveCANID = 2;
    constexpr int kBackLeftDriveCANID = 7;
    constexpr int kBackRightDriveCANID = 3;

    constexpr int kFrontLeftTurnCANID = 5;
    constexpr int kFrontRightTurnCANID = 1;
    constexpr int kBackLeftTurnCANID = 8;
    constexpr int kBackRightTurnCANID = 4;
}

// Note: VALUES SHOULD BE CHANGED
namespace AutoConstants 
{
    // constexpr auto kMaxSpeed = 3_mps;
    // constexpr auto kMaxAcceleration = 3_mps_sq;
    // constexpr auto kMaxAngularSpeed = 3.142_rad_per_s;
    // constexpr auto kMaxAngularAcceleration = 3.142_rad_per_s_sq;

    // constexpr double kPXController = 0.5;
    // constexpr double kPYController = 0.5;
    // constexpr double kPThetaController = 0.5;

    // extern const frc::TrapezoidProfile<units::radians>::Constraints kThetaControllerConstraints;
}

// Note: VALUES SHOULD BE CHANGED
namespace OIConstants
{
    constexpr int kDriveControllerPort = 0;
    constexpr double kDriveDeadband = 0.1;
}