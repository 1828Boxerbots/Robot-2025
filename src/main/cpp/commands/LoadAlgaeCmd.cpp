#include "commands/LoadAlgaeCmd.hpp"

LoadAlgaeCmd::LoadAlgaeCmd()
{

}

LoadAlgaeCmd::~LoadAlgaeCmd()
{

}

frc2::CommandPtr LoadAlgaeCmd::LoadAlgaeCmdFunction(int PivotLevel, int ElevatorLevel)
{
    //Once vision is fully implemented, Align command will come first
    if(m_intakeSubsystem.IsBallIn() == false)
    {
        std::move(m_pivotSubsystem.SetAngle(PivotLevel)).AndThen(std::move(m_elevatorSubsystem.MoveLevel(ElevatorLevel))).AndThen(std::move(m_intakeSubsystem.Load(IntakeConstants::kSpeed)));
        //
    }
}

