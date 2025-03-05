// #include "subsystems/Camera.hpp"

// namespace Robot2025
// {

//     // Constructor:
//     Camera::Camera(const std::string& camName) 
// 	{     
// 		m_camera = std::make_unique<photon::PhotonCamera>(camName);
// 	}

//     // Target Values (Change each season):
//     units::meter_t Camera::AprilTagHeightMeters(int aprilTagID)
//     {
//         // Grab apriltag height in meters.
// 		// Note: Height = center.
// 		// Variables.
//         units::meter_t aprilTagHeight = 0.0_m;
// 		units::meter_t coralStation = 1.485_m;
// 		units::meter_t processor = 1.305_m;
// 		units::meter_t reef = 0.305_m;
// 		units::meter_t barge = 1.915_m;

// 		// Set height depending on ID.
// 		switch (aprilTagID)
// 		{
// 		case 1:
// 		case 2:
// 			aprilTagHeight = coralStation;
// 			break;

// 		case 3:
// 			aprilTagHeight = processor;
// 			break;

// 		case 4:
// 		case 5:
// 			aprilTagHeight = barge;
// 			break;

// 		case 6:
// 		case 8:
// 		case 9:
// 		case 10:
// 		case 11:
// 			aprilTagHeight = reef;
// 			break;

// 		case 12:
// 		case 13:
// 			aprilTagHeight = coralStation;
// 			break;

// 		case 14:
// 		case 15:
// 			aprilTagHeight = barge;
// 			break;

// 		case 16:
// 			aprilTagHeight = processor;
// 			break;

// 		case 17:
// 		case 18:
// 		case 19:
// 		case 20:
// 		case 21:
// 		case 22:
// 			aprilTagHeight = reef;
// 			break;

// 		default:
// 			break;
// 		}

// 		return 	aprilTagHeight;
//     }

//     std::string Camera::AprilTagGameLocation(int aprilTagID)
//     {
//         // Grab apriltag game location name.
// 		// Variables.
//         std::string aprilTagGameLocation = " ";
// 		std::string coralStation = "Coral Station";
// 		std::string processor = "Processor";
// 		std::string reef = "Reef";
// 		std::string barge = "Barge";

// 		// Set game location name depending on ID.
// 		switch (aprilTagID)
// 		{
// 		case 1:
// 		case 2:
// 			aprilTagGameLocation = coralStation;
// 			break;

// 		case 3:
// 			aprilTagGameLocation = processor;
// 			break;

// 		case 4:
// 		case 5:
// 			aprilTagGameLocation = barge;
// 			break;

// 		case 6:
// 		case 8:
// 		case 9:
// 		case 10:
// 		case 11:
// 			aprilTagGameLocation = reef;
// 			break;

// 		case 12:
// 		case 13:
// 			aprilTagGameLocation = coralStation;
// 			break;

// 		case 14:
// 		case 15:
// 			aprilTagGameLocation = barge;
// 			break;

// 		case 16:
// 			aprilTagGameLocation = processor;
// 			break;

// 		case 17:
// 		case 18:
// 		case 19:
// 		case 20:
// 		case 21:
// 		case 22:
// 			aprilTagGameLocation = reef;
// 			break;

// 		default:
// 			break;
// 		}

// 		return 	aprilTagGameLocation;
//     }

//     // Periodic Function:
//     void Camera::ProcessCamAprilTags()
//     {
// 		// Clear previous targets.
// 		m_aprilTags.clear();
		
// 		// Get camera result.
// 		std::vector<photon::PhotonPipelineResult> unreadCamResults = m_camera->GetAllUnreadResults();

// 		// Loop through the unread results from camera.
// 		for(const photon::PhotonPipelineResult& camResult : unreadCamResults)
// 		{
// 			// Check if there are targets.
// 			if(camResult.HasTargets() == false)
// 			{
// 				std::cerr << "ERROR: No targets found." << std::endl;
// 				continue;
// 			}

// 			// Get targets from result and get the amount of targets
// 			std::span<const photon::PhotonTrackedTarget, 4294967295U> aprilTagTargets = camResult.GetTargets();

// 			// Loop through all targets to save data.
// 			for (const photon::PhotonTrackedTarget &target : aprilTagTargets)
// 			{
// 				// Get apriltag ID.
// 				int targetID = target.GetFiducialId(); //AprilTag ID.

// 				// Get apriltag game location.
// 				std::string targetGameLocation = AprilTagGameLocation(targetID); //Apriltag location relative to game area.

// 				// Get apriltag height.
// 				units::meter_t targetHeightMeters = AprilTagHeightMeters(targetID); //Apriltag height in meters from center of target to floor.
// 				double targetHeightDouble = targetHeightMeters.value(); 
// 				// Get apriltag pitch.
// 				double targetPitchDouble = target.GetPitch(); //Apriltag pitch in degrees.
// 				units::radian_t targetPitchDegrees = units::degree_t{targetPitchDouble};

// 				// Get apriltag estimated distance.
// 				units::meter_t targetDistMeters = photon::PhotonUtils::CalculateDistanceToTarget(m_camHeightMeters, targetHeightMeters, m_camPitchDegrees, targetPitchDegrees); //Apriltag distance from camera in meters.
// 				double targetDistDouble = targetDistMeters.value();

// 				// Save apriltag data.
// 				AprilTag curTag;
// 				curTag.SetID(targetID);
// 				curTag.SetDistance(targetDistDouble);
// 				curTag.SetHeight(targetHeightDouble);
// 				curTag.SetYaw(target.GetYaw());
// 				curTag.SetPitch(targetPitchDouble);
// 				curTag.SetSkew(target.GetSkew());
// 				curTag.SetGameLocation(targetGameLocation);

// 				m_aprilTags.push_back(curTag);
// 			}
// 		}
			
//         return;
// 	} 

// 	// Data Function:
//     AprilTag Camera::AprilTagsData(int member)
// 	{
// 		if (m_aprilTags.size() > 0)
// 		{
// 			return m_aprilTags[member];
// 		}
// 		else
// 		{
// 			std::cerr << "ERROR: No apriltag data." << std::endl;
// 			return AprilTag();
// 		}
// 	}

//     std::vector<AprilTag> Camera::AprilTagsDataArray()
// 	{
// 		if (m_aprilTags.size() > 0)
// 		{
// 			return m_aprilTags;
// 		}
// 		else
// 		{
// 			std::cerr << "ERROR: No apriltag data." << std::endl;
// 			return std::vector<AprilTag>();
// 		}
// 	}

//     // Destructor:
//     Camera::~Camera() 
// 	{
// 		m_camera->~PhotonCamera();
// 	}

// }