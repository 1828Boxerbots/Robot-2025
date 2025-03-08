
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/config/SparkMaxConfig.h>
#include <frc/DigitalInput.h>
#include <frc/AnalogPotentiometer.h>

#include "Constants.h"

class PivotSubsystem : public frc2::SubsystemBase {
 public:
  PivotSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.

  void Set(double power);

  bool GetLeftSafety() const;
  bool GetRightSafety() const;

    double GetPot() const;

 private:
    rev::spark::SparkMax m_pivotSpark;
    frc::DigitalInput m_leftSafety {PivotConstants::kleftSafetyDioPort};
    frc::DigitalInput m_rightSafety {PivotConstants::krightSafetyDioPort};
    frc::AnalogInput m_analogIn {PivotConstants::kpot};
    frc::AnalogPotentiometer m_Pot {&m_analogIn, 3600, 0};

    static rev::spark::SparkMaxConfig& PivotConfig() 
    {
        static rev::spark::SparkMaxConfig pivotConfig{};

        pivotConfig.SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake)
            .SmartCurrentLimit(50);
    
        return pivotConfig;
  }
};
