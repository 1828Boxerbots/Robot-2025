// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace CameraConstants 
{

//Camera constants



}  // namespace OperatorConstants

namespace ClimbConstants 
{
    //Climbconstants
inline constexpr int kClimbMotorPort1 = 0;
inline constexpr int kClimbMotorPort2 = 1;


}  

namespace CorralConstants 
{
    //Corral constants

inline constexpr int kCoralMotorPort1 = 2;
inline constexpr int kCoralMotorPort2 = 3;

}  


namespace DriveConstants 
{
        //Drive constants

inline constexpr int kDriverControllerPort = 0;


}  





namespace IntakeConstants 
{
    //Intake constants
    inline constexpr int kIntakeMotorPort1 = 4;
    inline constexpr int kIntakeMotorPort2 = 5;


}  

namespace ShooterConstants 
{
    //Shooter constants
    
    inline constexpr int kShooterMotorPort1 = 6;
    inline constexpr int kShooterMotorPort2 = 7;


}  