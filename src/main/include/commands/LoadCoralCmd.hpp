#include "subsystems/Guaco.hpp"
#include "subsystems/Pivot.h"
#include "subsystems/Elevator.hpp"
#include "subsystems/Camera.hpp"

class LoadCoralCmd
{
public:

    LoadCoralCmd();
    ~LoadCoralCmd();

    frc2::CommandPtr LoadCoralCmdFunction();

    Robot2025::Pivot m_pivotSubsystem;
    Robot2025::Elevator m_elevatorSubsystem;
    Robot2025::Guaco m_guacoSubsystem;
    //Change namespace of Camera Robo2025 to Robot2025
    Robo2025::Camera m_visionSubsystem;
};
