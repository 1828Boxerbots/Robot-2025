#pragma once
#include "rev/SparkMax.h";
#include "frc/Encoder.h";
#include "Constants.h"

namespace Robo2025
{
   

class Climb
{
   public:

//Public Methods:

   Climb();
   ~Climb();


  
   
  



   private:


// Private Member variables:

   rev::spark::SparkMax m_climbMotor1{ClimbConstants::kClimbMotorPort1, rev::spark::SparkMax::MotorType::kBrushless};
   rev::spark::SparkMax m_climbMotor2{ClimbConstants::kClimbMotorPort2, rev::spark::SparkMax::MotorType::kBrushless};


 //Private Methods
   
   /// @brief Climbs up >_<
   void ClimbUp();
};

}