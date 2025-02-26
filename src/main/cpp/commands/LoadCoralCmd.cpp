#include "commands/LoadCoralCmd.hpp"

LoadCoralCmd::LoadCoralCmd()
{

}

LoadCoralCmd::~LoadCoralCmd()
{

}

frc2::CommandPtr LoadCoralCmd::LoadCoralCmdFunction()
{
    //Once vision is fully implemented, Align command will come first
    if(m_guacoSubsystem.GetPhotogate() != true)
    {
        std::move(m_pivotSubsystem.SetAngle(PivotConstants::kCoralLoadAngle)).AndThen(std::move(m_elevatorSubsystem.MoveLevel(ElevatorConstants::kL3))).AndThen(std::move(m_guacoSubsystem.Load(GuacoConstants::kSpeed)));
        //move L3 is a placeholder until true level for coral loading is found. 
    }
    
}

