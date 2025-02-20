#pragma once
#include <iostream>
#include <string>
#include <photon/PhotonCamera.h>
#include <photon/PhotonUtils.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/angle.h>
#include <units/length.h>

#include "AprilTag.hpp"
#include "Constants.hpp"

namespace Robot2025
{

class Camera
{
    public:
    // Constructor:
    Camera();
    
    // Periodic Function:
    void ProcessCamAprilTags();

    // Destructor:
    ~Camera();

    private:
    // Initialize Camera(s)
    photon::PhotonCamera m_camera{"<Input Name>"};

    units::meter_t m_camHeight = 0.0_m;
    units::radian_t m_camPitch = 0.0_rad;
    units::radian_t m_targetPitch = 0.0_rad;

    std::vector<AprilTag> m_aprilTags;

    // Functions:
    units::meter_t AprilTagHeightMeters(int aprilTagID);
    std::string AprilTagGameLocation(int aprilTagID);
};

}