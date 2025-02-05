#include "subsystems/Elevator.hpp"
#include "subsystems/Guaco.hpp"
#include "subsystems/Camera.hpp"
#include "subsystems/Pivot.hpp"

class DispenseCoralCmd
{
public:

DispenseCoralCmd();
~DispenseCoralCmd();

frc2::CommandPtr DispenseCoralCmdFunction(int CoralLevel);

   Robot2025::Pivot m_pivotSubsystem;
    Robot2025::Elevator m_elevatorSubsystem;
    Robot2025::Guaco m_guacoSubsystem;
    //Change namespace of Camera Robo2025 to Robot2025
    Robot2025::Camera m_visionSubsystem;


};