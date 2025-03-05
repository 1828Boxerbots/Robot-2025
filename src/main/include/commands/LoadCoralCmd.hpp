#pragma once
#include "subsystems/Guaco.hpp"
#include "subsystems/Pivot.hpp"
#include "subsystems/Elevator.hpp"
#include "subsystems/Camera.hpp"

class LoadCoralCmd
{
public:

    LoadCoralCmd(Robot2025::Pivot& p, Robot2025::Elevator& e, Robot2025::Guaco& g);
    ~LoadCoralCmd();

    frc2::CommandPtr LoadCoralCmdFunction();

    Robot2025::Pivot* m_pivotSubsystem = nullptr;
    Robot2025::Elevator* m_elevatorSubsystem = nullptr;
    Robot2025::Guaco* m_guacoSubsystem = nullptr;
    //Change namespace of Camera Robo2025 to Robot2025
    //Robot2025::Camera m_visionSubsystem;
};
