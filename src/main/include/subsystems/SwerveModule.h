// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <rev/SparkMax.h>
#include <rev/SparkAbsoluteEncoder.h>
#include <rev/SparkClosedLoopController.h>
#include <rev/SparkRelativeEncoder.h>

class SwerveModule 
{
 public:
  SwerveModule(int driveCANID, int turningCANID, double chassisAngularOffset);

  frc::SwerveModuleState GetState() const;
  frc::SwerveModulePosition GetPosition() const;

  void SetDesiredState(const frc::SwerveModuleState& desiredState);
  void ResetEncoders();
  
 private:
  rev::CANSparkMax m_DriveSparkMax;
  rev::CANSparkMax m_TurnSparkMax;

  rev::SparkRelativeEncoder m_DriveEncoderRel = m_DriveSparkMax.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor, 42); //CHANGE, REVOLUTION COUNTS
  rev::SparkAbsoluteEncoder m_TurnEncoderAbs = m_TurnSparkMax.GetAbsoluteEncoder(rev::SparkAbsoluteEncoder::Type::kDutyCycle);

  rev::SparkPIDController m_DrivePIDController = m_DriveSparkMax.GetPIDController();
  rev::SparkPIDController m_TurnPIDController = m_TurnSparkMax.GetPIDController();

  frc::SwerveModuleState m_DesiredState{units::meters_per_second_t{0.0}, frc::Rotation2d()};
  
  double m_ChassisAngularOffset = 0;
};
