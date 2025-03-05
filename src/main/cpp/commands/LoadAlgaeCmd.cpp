#include "commands/LoadAlgaeCmd.hpp"

LoadAlgaeCmd::LoadAlgaeCmd(Robot2025::Pivot& p, Robot2025::Elevator& e, Robot2025::Intake& i)
{
    m_pivotSubsystem = &p;
    m_elevatorSubsystem = &e; 
    m_intakeSubsystem = &i;
}

LoadAlgaeCmd::~LoadAlgaeCmd()
{

}

frc2::CommandPtr LoadAlgaeCmd::LoadAlgaeCmdFunction(int PivotLevel, int ElevatorLevel)
{
    //Once vision is fully implemented, Align command will come first
    if ((m_pivotSubsystem != nullptr) and (m_elevatorSubsystem != nullptr) and (m_intakeSubsystem != nullptr))
    {
         if(m_intakeSubsystem->IsBallIn() == false)
    {
        std::move(m_pivotSubsystem->SetAngle(PivotLevel)).AndThen(std::move(m_elevatorSubsystem->MoveLevel(ElevatorLevel))).AndThen(std::move(m_intakeSubsystem->Load(IntakeConstants::kSpeed)));
        //
    } 
    }
   
}

