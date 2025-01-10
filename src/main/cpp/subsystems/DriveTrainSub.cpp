// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrainSub.h"

#include <frc/geometry/Rotation2d.h>
#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/velocity.h>

#include "Constants.h"
#include "SwerveUtils.h"

using namespace DriveConstants;

DriveTrainSub::DriveTrainSub() : m_FrontLeft{kFrontLeftDriveCANID, kFrontLeftTurnCANID, kFrontLeftChassisAngularOffset}, m_BackLeft{kBackLeftDriveCANID, kBackLeftTurnCANID,kBackLeftChassisAngularOffset}, m_FrontRight{kFrontRightDriveCANID, kFrontRightTurnCANID, kFrontRightChassisAngularOffset}, m_BackRight{kBackRightDriveCANID, kBackRightTurnCANID, kBackRightChassisAngularOffset} {}

void DriveTrainSub::Periodic() {}

void DriveTrainSub::Drive(units::meters_per_second_t xSpeed, units::meters_per_second_t ySpeed, units::radians_per_second_t rot, bool fieldRelative, bool rateLimit)
{
    units::meters_per_second_t xSpeedDelivered = xSpeed.value() * kMaxSpeed;
    units::meters_per_second_t ySpeedDelivered = ySpeed.value() * kMaxSpeed;
    units::radians_per_second_t rotDelivered = rot.value() * kMaxAngularSpeed;

    auto states = kDriveKinematics.ToSwerveModuleStates(fieldRelative ? frc::ChassisSpeeds::FromFieldRelativeSpeeds(xSpeedDelivered, ySpeedDelivered, rotDelivered, frc::Rotation2d(units::radian_t{m_Gyro.GetAngle(frc::ADIS16470_IMU::IMUAxis::kZ)})) : frc::ChassisSpeeds{xSpeedDelivered, ySpeedDelivered, rotDelivered});

    kDriveKinematics.DesaturateWheelSpeeds(&states, DriveConstants::kMaxSpeed);

    auto [fl, fr, bl, br] = states;

    m_FrontLeft.SetDesiredState(fl);
    m_FrontRight.SetDesiredState(fr);
    m_BackLeft.SetDesiredState(bl);
    m_BackRight.SetDesiredState(br);
}

void DriveTrainSub::SetXShapeWheelFormation() 
{
    m_FrontLeft.SetDesiredState(frc::SwerveModuleState{0_mps, frc::Rotation2d{45_deg}});
    m_FrontRight.SetDesiredState(frc::SwerveModuleState{0_mps, frc::Rotation2d{-45_deg}});
    m_BackLeft.SetDesiredState(frc::SwerveModuleState{0_mps, frc::Rotation2d{-45_deg}});
    m_BackRight.SetDesiredState(frc::SwerveModuleState{0_mps, frc::Rotation2d{45_deg}});
}

void DriveTrainSub::SetModuleStates(wpi::array<frc::SwerveModuleState, 4> desiredStates) 
{
    kDriveKinematics.DesaturateWheelSpeeds(&desiredStates, DriveConstants::kMaxSpeed);
    m_FrontLeft.SetDesiredState(desiredStates[0]);
    m_FrontRight.SetDesiredState(desiredStates[1]);
    m_BackLeft.SetDesiredState(desiredStates[2]);
    m_BackRight.SetDesiredState(desiredStates[3]);
}

void DriveTrainSub::ResetEncoders() 
{
    m_FrontLeft.ResetEncoders();
    m_FrontRight.ResetEncoders();
    m_BackLeft.ResetEncoders();
    m_BackRight.ResetEncoders();
}

units::degree_t DriveTrainSub::GetHeading() const 
{
  return frc::Rotation2d(units::radian_t{m_Gyro.GetAngle(frc::ADIS16470_IMU::IMUAxis::kZ)}).Degrees();
}

void DriveTrainSub::ZeroHeading() 
{ 
    m_Gyro.Reset(); 
}

double DriveTrainSub::GetTurnRate() 
{
    return -m_Gyro.GetRate(frc::ADIS16470_IMU::IMUAxis::kZ).value();
}