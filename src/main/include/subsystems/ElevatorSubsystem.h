
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/config/SparkMaxConfig.h>
#include <frc/DigitalInput.h>

#include "Constants.h"

class ElevatorSubsystem : public frc2::SubsystemBase {
 public:
  ElevatorSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.

  void Set(double power);

  bool GetUpperSafety() const;
  bool GetLowerSafety() const;

  double GetHeight() const;

 private:
    rev::spark::SparkMax m_elevatorSpark;
    rev::spark::SparkRelativeEncoder m_elvatorEncoder = m_elevatorSpark.GetEncoder();

    frc::DigitalInput m_upperSafety {ElevatorConstants::kupperSafetyDioPort};
    frc::DigitalInput m_lowerSafety {ElevatorConstants::klowerSafetyDioPort};

    static rev::spark::SparkMaxConfig& ElevatorConfig() 
    {
        static rev::spark::SparkMaxConfig elevatorConfig{};

        double conversionFactor = ElevatorConstants::kDiameter.value() *
                           std::numbers::pi /
                           ElevatorConstants::kmotorReduction;

        elevatorConfig.SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake)
            .SmartCurrentLimit(50);
        elevatorConfig.encoder
            .PositionConversionFactor(conversionFactor)          // inches
            .VelocityConversionFactor(conversionFactor / 60.0);  // inches per second
    
        return elevatorConfig;
  }
};
