#include "subsystems/Camera.hpp"

namespace Robot2025
{

    // Constructor:
    Camera::Camera() {}

    // Target Values (Change each season):
    units::meter_t Camera::AprilTagHeightMeters(int aprilTagID)
    {
        // Grab apriltag height in meters.
		// Note: Height = center.

		// Variables.
        units::meter_t aprilTagHeight = 0.0_m;
		units::meter_t coralStation = 1.485_m;
		units::meter_t processor = 1.305_m;
		units::meter_t reef = 0.305_m;
		units::meter_t barge = 1.915_m;

		// Set height depending on ID.
		switch (aprilTagID)
		{
		case 1:
		case 2:
			aprilTagHeight = coralStation;
			break;

		case 3:
			aprilTagHeight = processor;
			break;

		case 4:
		case 5:
			aprilTagHeight = barge;
			break;

		case 6:
		case 8:
		case 9:
		case 10:
		case 11:
			aprilTagHeight = reef;
			break;

		case 12:
		case 13:
			aprilTagHeight = coralStation;
			break;

		case 14:
		case 15:
			aprilTagHeight = barge;
			break;

		case 16:
			aprilTagHeight = processor;
			break;

		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
			aprilTagHeight = reef;
			break;

		default:
			break;
		}

		return 	aprilTagHeight;
    }

    std::string Camera::AprilTagGameLocation(int aprilTagID)
    {
        // Grab apriltag game location name.

		// Variables.
        std::string aprilTagGameLocation = " ";
		std::string coralStation = "Coral Station";
		std::string processor = "Processor";
		std::string reef = "Reef";
		std::string barge = "Barge";

		// Set game location name depending on ID.
		switch (aprilTagID)
		{
		case 1:
		case 2:
			aprilTagGameLocation = coralStation;
			break;

		case 3:
			aprilTagGameLocation = processor;
			break;

		case 4:
		case 5:
			aprilTagGameLocation = barge;
			break;

		case 6:
		case 8:
		case 9:
		case 10:
		case 11:
			aprilTagGameLocation = reef;
			break;

		case 12:
		case 13:
			aprilTagGameLocation = coralStation;
			break;

		case 14:
		case 15:
			aprilTagGameLocation = barge;
			break;

		case 16:
			aprilTagGameLocation = processor;
			break;

		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
			aprilTagGameLocation = reef;
			break;

		default:
			break;
		}

		return 	aprilTagGameLocation;
    }

    // Periodic Function:
    void Camera::ProcessCamAprilTags()
    {
        photon::PhotonPipelineResult camResult = m_camera.GetLatestResult();

        if(camResult.HasTargets() == false)
        {
            return;
        }

        m_aprilTagTargets = camResult.GetTargets();
        unsigned int aprilTagArraySize = m_aprilTagTargets.size();

        for (int i = 0; i < aprilTagArraySize; i++)
        {
            photon::PhotonTrackedTarget target = m_aprilTagTargets[i];
            
            int targetID = target.GetFiducialId();
            units::meter_t targetHeightMeters = AprilTagHeightMeters(targetID);

            double targetHeightDouble = targetHeightMeters.value();
            std::string targetGameLocation = AprilTagGameLocation(targetID);

            units::meter_t targetDistMeters = photon::PhotonUtils::CalculateDistanceToTarget(m_camHeight, targetHeightMeters, m_camPitch, m_targetPitch);
            double targetDistDouble = targetDistMeters.value();

            AprilTag curTag;
            curTag.SetID(targetID);
            curTag.SetDistance(targetDistDouble);
            curTag.SetHeight(targetHeightDouble);
            curTag.SetYaw(target.GetYaw());
            curTag.SetPitch(target.GetPitch());
            curTag.SetSkew(target.GetSkew());
            curTag.SetGameLocation(targetGameLocation);
        }
    }

    // Destructor:
    Camera::~Camera() {}

}