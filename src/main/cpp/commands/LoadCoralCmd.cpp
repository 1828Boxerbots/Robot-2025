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
    std::move(m_guacoSubsystem.PhotodiodeThreshold()).Andthen(std::move())
}