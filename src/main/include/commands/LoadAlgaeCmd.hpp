#include "subsystems/Intake.hpp"
#include "subsystems/Pivot.h"
#include "subsystems/Elevator.hpp"
#include "subsystems/Camera.hpp"

class LoadAlgaeCmd
{
public:

    LoadAlgaeCmd();
    ~LoadAlgaeCmd();

    frc2::CommandPtr LoadAlgaeCmdFunction(int PivotLevel, int ElevatorLevel);

    Robot2025::Pivot m_pivotSubsystem;
    Robot2025::Elevator m_elevatorSubsystem;
    Robot2025::Intake m_intakeSubsystem;
    //Change namespace of Camera Robo2025 to Robot2025
    Robo2025::Camera m_visionSubsystem;
};
