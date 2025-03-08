
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/config/SparkMaxConfig.h>
#include <frc/DigitalInput.h>

#include "Constants.h"

class AlgaeSubsystem : public frc2::SubsystemBase {
 public:
  AlgaeSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.

  void Set(double power);

  bool GetLimitSwitch() const;

 private:
    rev::spark::SparkMax m_AlgaeSpark;
    frc::DigitalInput m_limitSwitch {AlgaeConstants::kAlgaeDioPort};

    static rev::spark::SparkMaxConfig& AlgaeConfig() 
    {
        static rev::spark::SparkMaxConfig AlgaeConfig{};

        AlgaeConfig.SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake)
            .SmartCurrentLimit(50);

        return AlgaeConfig;
  }
};
