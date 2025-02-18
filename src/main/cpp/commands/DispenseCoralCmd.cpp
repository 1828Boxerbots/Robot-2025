#include "commands/DispenseCoralCmd.hpp"

DispenseCoralCmd::DispenseCoralCmd()
{

}

DispenseCoralCmd::~DispenseCoralCmd()
{

}

frc2::CommandPtr DispenseCoralCmd::DispenseCoralCmdFunction(int CoralLevel)
{
    //CoralLevel = Level to put coral on reef 
   std::move(m_pivotSubsystem.SetAngle(PivotConstants::kCoralAngle)).AndThen(std::move(m_elevatorSubsystem.MoveLevel(CoralLevel))).AndThen(std::move(m_guacoSubsystem.Dispense(GuacoConstants::kSpeed)));
   
    
}

