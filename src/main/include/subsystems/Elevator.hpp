#pragma once
#include "Constants.h"

#include <frc/Encoder.h>
#include <frc/DigitalOutput.h>

#include <rev/SparkMax.h>
#include <rev/SparkClosedLoopController.h>
#include <frc2/command/CommandPtr.h> 
#include <frc2/command/SubsystemBase.h>

namespace Robot2025
{

class Elevator : public frc2::SubsystemBase
{
    public:

//Public Methods:

    Elevator();
    ~Elevator();

    //getters / setters

//Hall effects

bool GetHallEffectL1();

bool GetHallEffectL2();

bool GetHallEffectL3();

bool GetHallEffectL4();


//Motors 
    
int GetMotorValue();

frc2::CommandPtr SetMotorValue(int value);

int GetEncoderValue();
  

  
/// @brief Moves height of taco to Level 1 on the reef (trough)
frc2::CommandPtr MoveL1();

/// @brief Moves height of taco to Level 2 on the reef 
frc2::CommandPtr MoveL2();

/// @brief Moves height of taco to Level 3 on the reef 
frc2::CommandPtr MoveL3();

/// @brief Moves height of taco to Level 4 on the reef 
frc2::CommandPtr MoveL4();
  

  

    private:



//Private Member varibles:




//Motors

/// @brief Elevator Motor 1
rev::spark::SparkMax m_ElevatorMotor1{ElevatorConstants::kElevatorMotorPort1, rev::spark::SparkMax::MotorType::kBrushless};

//PIDS
rev::spark::SparkClosedLoopController m_controller = m_ElevatorMotor1.GetClosedLoopController();


//Hall effect sensors



/// @brief Hall Effect sensor for the first level (trough)
/// @return 
frc::DigitalOutput m_HallEffectL1{ElevatorConstants::kHallEffectPortL1};



/// @brief Hall Effect sensor for the Second level
/// @return 
frc::DigitalOutput m_HallEffectL2{ElevatorConstants::kHallEffectPortL2};

/// @brief Hall Effect sensor for the Third level
/// @return 
frc::DigitalOutput m_HallEffectL3{ElevatorConstants::kHallEffectPortL3};

/// @brief Hall Effect sensor for the fourth level
/// @return 
frc::DigitalOutput m_HallEffectL4{ElevatorConstants::kHallEffectPortL4};



//Encoders

frc::Encoder m_ElevatorEncoder{ElevatorConstants::kEncoderPortA, ElevatorConstants::kEncoderPortB};
 
//Private Methods






    
};
}