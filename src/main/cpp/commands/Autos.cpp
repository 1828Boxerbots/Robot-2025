// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.hpp"

#include <frc2/command/Commands.h>

#include "commands/ExampleCommand.hpp"

#include "frc/trajectory/constraint/SwerveDriveKinematicsConstraint.h"



frc2::CommandPtr autos::AutosCmd(ExampleSubsystem* subsystem) 
{



  return frc2::cmd::Sequence(ExampleSubsystem* subsystem->ExampleMethodCommand(),
                             ExampleCommand(subsystem).ToPtr());

}

