#pragma once
#include "rev/SparkMax.h"
#include "Constants.h"
#include "frc/DigitalOutput.h"
#include "frc/AnalogInput.h"

namespace Robo2025
{

class Guaco
{

public:

//public methods

    Guaco();
    ~Guaco();

private: 

//private member variables

    rev::spark::SparkMax m_guacoMotor{GuacoConstants::kGuacoMotorPort, rev::spark::SparkMax::MotorType::kBrushed};
    frc::AnalogInput m_photodiode{GuacoConstants::kPhotodiodePort};
    

//private methods

    /// @brief Finds out what the voltage of the photodiode
    /// @return The voltage of it
    double GetPhotodiodeVoltage();

    /// @brief Compare and check if coral inside Guaco
    /// @return True is pass and false if is doesn't pass
    bool PhotodiodeThreshold();

    /// @brief Used to set the speed the motor needs to go
    void SetMotorSpeed(double speed);

};

}
