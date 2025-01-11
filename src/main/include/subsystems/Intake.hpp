#pragma once
#include "rev/SparkMax.h"

namespace Robo2025

{

class Intake
{
   public:

   private:

//member variables

rev::spark::SparkMax m_loadmotor1{0, rev::spark::SparkMax::MotorType::kBrushless};
rev::spark::SparkMax m_loadMotor2{1, rev::spark::SparkMax::MotorType::kBrushless};


 /*
  Sensors to add:
   
   Encoders
   Motor controlers
   Photogate

  */ 


//methods
   bool m_IsBallIn();




};

}