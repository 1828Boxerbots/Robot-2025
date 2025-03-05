#pragma once

#include <rev/SparkMax.h>
#include "Constants.hpp"
#include <frc/DigitalInput.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc/smartdashboard/SmartDashboard.h>

namespace Robot2025
{

class Guaco : public frc2::SubsystemBase
{

public:

//public methods

    Guaco();
    ~Guaco();
    void Init();
    void Periodic() override;


//private member variables

    rev::spark::SparkMax m_guacoMotor{GuacoConstants::kGuacoMotorPort, rev::spark::SparkMax::MotorType::kBrushed};
    frc::DigitalInput m_photogate{GuacoConstants::kPhotogatePort};
    

//private methods

    /// @brief Finds out what the voltage of the photodiode
    /// @return The voltage of it
    double GetPhotogate();

    /// @brief Compare and check if coral inside Guaco
    /// @return True is pass and false if is doesn't pass
    //bool PhotodiodeThreshold();

    /// @brief Used to set the speed the motor needs to go
    frc2::FunctionalCommand Dispense(double speed, Robot2025::Guaco& guaco);
    frc2::FunctionalCommand Load(double speed, Robot2025::Guaco& guaco);

    private: 

};

}
