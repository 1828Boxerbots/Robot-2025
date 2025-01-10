// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SwerveModule.h"
#include <frc/geometry/Rotation2d.h>
#include <numbers>
#include "Constants.h"
using namespace ModuleConstants;

SwerveModule::SwerveModule(int driveCANID, int turnCANID, double chassisAngularOffset) : m_DriveSparkMax(driveCANID, rev::CANSparkMax::MotorType::kBrushless),  m_TurnSparkMax(turnCANID, rev::CANSparkMax::MotorType::kBrushless)
{
    m_DriveSparkMax.RestoreFactoryDefaults();
    m_TurnSparkMax.RestoreFactoryDefaults();

    m_DriveEncoderRel.SetPositionConversionFactor(kDriveEncoderPosFactor);
    m_DriveEncoderRel.SetVelocityConversionFactor(kDriveEncoderVelFactor);

    m_TurnEncoderAbs.SetPositionConversionFactor(kTurnEncoderPosFactor);
    m_TurnEncoderAbs.SetVelocityConversionFactor(kTurnEncoderVelFactor);

    m_TurnEncoderAbs.SetInverted(kTurnEncoderInverted);

    m_TurnPIDController.SetPositionPIDWrappingEnabled(true);
    m_TurnPIDController.SetPositionPIDWrappingMinInput(kTurnEncoderPosPIDInputMin.value());
    m_TurnPIDController.SetPositionPIDWrappingMaxInput(kTurnEncoderPosPIDInputMax.value());

    m_TurnPIDController.SetFeedbackDevice(m_TurnEncoderAbs);

    m_DrivePIDController.SetP(kDriveP);
    m_DrivePIDController.SetI(kDriveI);
    m_DrivePIDController.SetD(kDriveD);
    m_DrivePIDController.SetFF(kDriveFF);
    m_DrivePIDController.SetOutputRange(kDriveOutputMin, kDriveOutputMax);

    m_TurnPIDController.SetP(kTurnP);
    m_TurnPIDController.SetI(kTurnI);
    m_TurnPIDController.SetD(kTurnD);
    m_TurnPIDController.SetFF(kTurnFF);
    m_TurnPIDController.SetOutputRange(kTurnOutputMin, kTurnOutputMax);

    m_DriveSparkMax.SetIdleMode(kDriveMotorIdleMode);
    m_TurnSparkMax.SetIdleMode(kTurnMotorIdleMode);
    m_DriveSparkMax.SetSmartCurrentLimit(kDriveMotorCurrentLimit.value());
    m_TurnSparkMax.SetSmartCurrentLimit(kTurnMotorCurrentLimit.value());

    m_DriveSparkMax.BurnFlash();
    m_TurnSparkMax.BurnFlash();

    m_ChassisAngularOffset = chassisAngularOffset;
    m_DesiredState.angle = frc::Rotation2d(units::radian_t{m_TurnEncoderAbs.GetPosition()});
    m_DriveEncoderRel.SetPosition(0);
}

frc::SwerveModuleState SwerveModule::GetState() const
{
     return {units::meters_per_second_t{m_DriveEncoderRel.GetVelocity()}, units::radian_t{m_TurnEncoderAbs.GetPosition() - m_ChassisAngularOffset}};
}

frc::SwerveModulePosition SwerveModule::GetPosition() const
{
  return {units::meter_t{m_DriveEncoderRel.GetPosition()}, units::radian_t{m_TurnEncoderAbs.GetPosition() - m_ChassisAngularOffset}};
}

void SwerveModule::SetDesiredState(const frc::SwerveModuleState& desiredState)
{
    frc::SwerveModuleState correctedDesiredState{};
    correctedDesiredState.speed = desiredState.speed;
    correctedDesiredState.angle = desiredState.angle + frc::Rotation2d(units::radian_t{m_ChassisAngularOffset});

    frc::SwerveModuleState optimizedDesiredState{frc::SwerveModuleState::Optimize(correctedDesiredState, frc::Rotation2d(units::radian_t{m_TurnEncoderAbs.GetPosition()}))};

    m_DrivePIDController.SetReference((double)optimizedDesiredState.speed, rev::CANSparkMax::ControlType::kVelocity);
    m_TurnPIDController.SetReference(optimizedDesiredState.angle.Radians().value(), rev::CANSparkMax::ControlType::kPosition);

    m_DesiredState = desiredState;
}

void SwerveModule::ResetEncoders()
{
    m_DriveEncoderRel.SetPosition(0);
}