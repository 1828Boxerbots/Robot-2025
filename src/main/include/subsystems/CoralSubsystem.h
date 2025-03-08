
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/config/SparkMaxConfig.h>
#include <frc/DigitalInput.h>

#include "Constants.h"

class CoralSubsystem : public frc2::SubsystemBase {
 public:
  CoralSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.

  void Set(double power);

  bool GetPhotogate() const;

 private:
    rev::spark::SparkMax m_coralSpark;
    frc::DigitalInput m_photogate {CoralConstants::kCoralDioPort};

    static rev::spark::SparkMaxConfig& CoralConfig() 
    {
        static rev::spark::SparkMaxConfig coralConfig{};

        coralConfig.SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake)
            .SmartCurrentLimit(50);

        return coralConfig;
  }
};
