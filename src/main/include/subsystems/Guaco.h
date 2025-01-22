#include <frc/servo.h> 
#include "Constants.h"


namespace Robo2025
{

class Guaco
{

public:

Guaco();
~Guaco();

private: 

frc::Servo m_guacoServo{GuacoConstants::kGuacoPort};

double GetAngle();
//get Servo Angle
void SetAngle(double angle);
//set Servo Angle

};

}
