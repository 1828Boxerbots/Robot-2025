#include "commands/DispenseCoralCmd.hpp"

DispenseCoralCmd::DispenseCoralCmd(Robot2025::Pivot& p, Robot2025::Elevator& e, Robot2025::Guaco& g)
{
    m_pivotSubsystem = &p;
    m_elevatorSubsystem = &e; 
    m_guacoSubsystem = &g;
}

DispenseCoralCmd::~DispenseCoralCmd()
{

}

frc2::CommandPtr DispenseCoralCmd::DispenseCoralCmdFunction(int CoralLevel)
{
    //CoralLevel = Level to put coral on reef 
    if ((m_pivotSubsystem != nullptr) and (m_elevatorSubsystem != nullptr) and (m_guacoSubsystem != nullptr))
    {
        std::move(m_pivotSubsystem->SetAngle(PivotConstants::kCoralAngle)).AndThen(std::move(m_elevatorSubsystem->MoveLevel(CoralLevel)));
    }
   
}

