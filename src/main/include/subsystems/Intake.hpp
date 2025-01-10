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
//SparkMax::LoadMotor2{};




//methods
   bool m_IsBallIn();


};

}