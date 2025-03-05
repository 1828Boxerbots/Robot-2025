#pragma once

#include "subsystems/Intake.hpp"
#include "subsystems/Pivot.hpp"
#include "subsystems/Elevator.hpp"
#include "subsystems/Camera.hpp"

class LoadAlgaeCmd
{
public:

    LoadAlgaeCmd(Robot2025::Pivot& p, Robot2025::Elevator& e, Robot2025::Intake& i);
    ~LoadAlgaeCmd();

    frc2::CommandPtr LoadAlgaeCmdFunction(int PivotLevel, int ElevatorLevel);

    Robot2025::Pivot* m_pivotSubsystem = nullptr;
    Robot2025::Elevator* m_elevatorSubsystem = nullptr;
    Robot2025::Intake* m_intakeSubsystem = nullptr;
    //Change namespace of Camera Robo2025 to Robot2025
    //Robot2025::Camera m_visionSubsystem;
};
