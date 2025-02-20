#pragma once
#include <iostream>
#include <string>
#include <photon/PhotonCamera.h>
#include <photon/PhotonUtils.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/angle.h>
#include <units/length.h>
#include <memory.h>

#include "AprilTag.hpp"
#include "Constants.hpp"

namespace Robot2025
{

class Camera
{
    public:
    // Constructor:
    Camera(const std::string& camName = "BoxerCam1");
    
    // Periodic Function:
    void ProcessCamAprilTags();

    // Data Function:
    AprilTag AprilTagsData(int member);
    std::vector<AprilTag> AprilTagsDataArray();

    // Destructor:
    ~Camera();

    private:
    // Initialize Camera(s)
    std::unique_ptr<photon::PhotonCamera> m_camera;

    units::meter_t m_camHeight = 0.0_m;
    units::radian_t m_camPitch = 0.0_rad;
    units::radian_t m_targetPitch = 0.0_rad;

    std::vector<AprilTag> m_aprilTags;

    // Functions:
    units::meter_t AprilTagHeightMeters(int aprilTagID);
    std::string AprilTagGameLocation(int aprilTagID);
};

}