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




//All ports = 0 for dummy values, change them later
namespace CameraConstants 
{

//Camera constants



}  // namespace OperatorConstants


namespace ClimbConstants 
{
    //Climbconstants
inline constexpr int kClimbMotorPort1 = 0;
inline constexpr int kClimbMotorPort2 = 0;


}  

namespace ElevatorConstants 
{
    //Elevator constants

inline constexpr int kElevatorMotorPort1 = 0;
inline constexpr int kElevatorMotorPort2 = 0;
inline constexpr int kHallEffectPortL1 = 0;
inline constexpr int kHallEffectPortL2 = 0;
inline constexpr int kHallEffectPortL3 = 0;
inline constexpr int kHallEffectPortL4 = 0;
inline constexpr int kEncoderPortA = 0;
inline constexpr int kEncoderPortB = 0;

namespace ElevatorPID
{
    //Pids constants
    inline constexpr int kSetPoint = 0;
    inline constexpr int kPosition = 0;

    inline constexpr int kP = 0;
    inline constexpr int kI = 0;
    inline constexpr int kD = 0;
    inline constexpr int kMaxOutput = 0;
    inline constexpr int kMinOutput = 0;
    inline constexpr int kv = 0;
    inline constexpr int kMaxVelocity = 0;
    inline constexpr int kMaxAcceleration = 0;
    inline constexpr int kAllowedError = 0;


}

}  


namespace DriveConstants 
{
        //Drive constants

inline constexpr int kDriverControllerPort = 0;


}  





namespace IntakeConstants 
{
    //Intake constants
    inline constexpr int kIntakeMotorPort1 = 0;
    inline constexpr int kIntakeMotorPort2 = 0;


}  

namespace ShooterConstants 
{
    //Shooter constants
    
    inline constexpr int kShooterMotorPort1 = 0;
    inline constexpr int kShooterMotorPort2 = 0;


}  

namespace DriverConstants
{
    inline constexpr int kDriverControllerPort = 0;
}