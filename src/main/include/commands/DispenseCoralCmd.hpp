#include "subsystems/Elevator.hpp"
#include "subsystems/Guaco.hpp"
#include "subsystems/Camera.hpp"
#include "subsystems/Pivot.hpp"

class DispenseCoralCmd
{
public:

DispenseCoralCmd(Robot2025::Pivot& p, Robot2025::Elevator& e, Robot2025::Guaco& g);
~DispenseCoralCmd();

frc2::CommandPtr DispenseCoralCmdFunction(int CoralLevel);

   Robot2025::Pivot* m_pivotSubsystem = nullptr;
    Robot2025::Elevator* m_elevatorSubsystem = nullptr;
    Robot2025::Guaco* m_guacoSubsystem = nullptr;
    //Change namespace of Camera Robo2025 to Robot2025
    //Robot2025::Camera m_visionSubsystem;

};