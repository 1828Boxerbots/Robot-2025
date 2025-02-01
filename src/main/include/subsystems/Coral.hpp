#pragma once
#include "rev/SparkMax.h"
#include "frc/AnalogPotentiometer.h"
#include "frc/Encoder.h"
#include "Constants.h"

namespace Robot2025
{

class Coral
{
    public:

//Public Methods:

    Coral();
    ~Coral();

  

  


  

    private:

//Private Member varibles:

rev::spark::SparkMax m_coralMotor1{CorralConstants::kCoralMotorPort1, rev::spark::SparkMax::MotorType::kBrushless};
rev::spark::SparkMax m_coralMotor1{CorralConstants::kCoralMotorPort2, rev::spark::SparkMax::MotorType::kBrushless};
 
//Private Methods

/// @brief  Removes gate and Tips lexan taco to place coral

void PlaceCoral();

/// @brief Moves height of taco to Level 1 on the reef (trough)
void MoveL1();

/// @brief Moves height of taco to Level 2 on the reef 
void MoveL2();

/// @brief Moves height of taco to Level 3 on the reef 
void MoveL3();

/// @brief Moves height of taco to Level 4 on the reef 
void MoveL4();
  


    
};
}