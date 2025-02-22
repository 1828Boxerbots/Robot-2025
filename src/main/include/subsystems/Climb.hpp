#pragma once

#include <rev/SparkMax.h>
#include <frc/Encoder.h>
#include "Constants.hpp"
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>


namespace Robot2025
{
   

class Climb : public frc2::SubsystemBase
{
   public:

//Public Methods:

   Climb();
   ~Climb();
   void Init();
   void Periodic() override;


  
   
  



   private:


// Private Member variables:

   rev::spark::SparkMax m_climbMotor1{ClimbConstants::kClimbMotorPort1, rev::spark::SparkMax::MotorType::kBrushless};
   rev::spark::SparkMax m_climbMotor2{ClimbConstants::kClimbMotorPort2, rev::spark::SparkMax::MotorType::kBrushless};


 //Private Methods
   
   /// @brief Climbs up >_<
   void ClimbUp();
};

}