#include "frc2/command/CommandPtr.h"
#include "frc2/command/CommandHelper.h"
#include "subsystems/Elevator.hpp"
#include "subsystems/Pivot.h"
#include "subsystems/Intake.hpp"

class ShootCmd 
{
    frc2::CommandPtr ShootBarge();
    Robot2025::Elevator m_elevatorSub;
    Robot2025::Intake m_intake;
    Robot2025::Pivot m_pivot;

    
};