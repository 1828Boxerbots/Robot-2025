// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/ADIS16470_IMU.h>
#include <frc/filter/SlewRateLimiter.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc2/command/SubsystemBase.h>

#include "SwerveModule.h"
#include "Constants.h"


class DriveTrainSub : public frc2::SubsystemBase 
{
 public:
  DriveTrainSub();
  void Periodic() override;

  void Drive(units::meters_per_second_t xSpeed,units::meters_per_second_t ySpeed, units::radians_per_second_t rot, bool fieldRelative, bool rateLimit);
  
  void SetModuleStates(wpi::array<frc::SwerveModuleState, 4> desiredStates);
  void SetXShapeWheelFormation();
  void ResetEncoders();
  void ZeroHeading();

  units::degree_t GetHeading() const;
  double GetTurnRate();
  frc::Pose2d GetPose();
  
  frc::SwerveDriveKinematics<4> kDriveKinematics{frc::Translation2d{DriveConstants::kWheelBase / 2, DriveConstants::kTrackWidth / 2}, frc::Translation2d{DriveConstants::kWheelBase / 2, -DriveConstants::kTrackWidth / 2}, frc::Translation2d{-DriveConstants::kWheelBase / 2, DriveConstants::kTrackWidth / 2}, frc::Translation2d{-DriveConstants::kWheelBase / 2,-DriveConstants::kTrackWidth / 2}};

 private:
 SwerveModule m_FrontLeft;
 SwerveModule m_BackLeft;
 SwerveModule m_FrontRight;
 SwerveModule m_BackRight;

  frc::ADIS16470_IMU m_Gyro;

  double m_CurrentRotation = 0.0;
  double m_CurrentTranslationDir = 0.0;
  double m_CurrentTranslationMag = 0.0;

  frc::SlewRateLimiter<units::scalar> m_MagLimiter{DriveConstants::kMagnitudeSlewRate / 1_s};
  frc::SlewRateLimiter<units::scalar> m_RotLimiter{DriveConstants::kRotationalSlewRate / 1_s};
  double m_PrevTime = wpi::Now() * 1e-6;
};
