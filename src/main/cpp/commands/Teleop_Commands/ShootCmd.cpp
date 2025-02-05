#include "commands/Teleop_Commands/ShootCmd.hpp"
frc2::CommandPtr ShootCmd::ShootBarge() 
{   //first one is dummy, actual valueis supposed to be Vision Align command
    std::move(m_pivot.SetAngle(PivotConstants::kBargeAngle)).AndThen(std::move(m_pivot.SetAngle(PivotConstants::kBargeAngle))).AndThen(std::move(m_elevatorSub.MoveL3())).AndThen(std::move(m_intake.SetMotors(IntakeConstants::kSpeed)));
}



