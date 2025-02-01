#include "AprilTag.h"

namespace BV
{
	// Setter Functions:
	void AprilTag::SetAprilTagID(const int& aprilTagID)
	{
		// Set apriltag ID.
		m_aprilTagID = aprilTagID;
		return;
	}

	void AprilTag::SetAprilTagDistance(const double& aprilTagDist)
	{
		// Set apriltag distance.
		m_aprilTagDist = aprilTagDist;
		return;
	}

	// Struct Functions:
	int AprilTag::GetAprilTagID()
	{
		// Grab apriltag ID.
		return 	m_aprilTagID;
	}

	double AprilTag::GetAprilTagDistanceMeters()
	{
		// Grab apriltag distance in meters.
		return 	m_aprilTagDist;
	}

	double AprilTag::GetAprilTagHeightMeters() // UPDATE EACH GAME SEASON
	{
		// Grab apriltag height in meters.
		// Note: Height = center.

		// Variables.
		double coralStation = 1.485;
		double processor = 1.305;
		double reef = 0.305;
		double barge = 1.915;

		// Set height depending on ID.
		switch (m_aprilTagID)
		{
		case 1:
		case 2:
			m_aprilTagHeight = coralStation;
			break;

		case 3:
			m_aprilTagHeight = processor;
			break;

		case 4:
		case 5:
			m_aprilTagHeight = barge;
			break;

		case 6:
		case 8:
		case 9:
		case 10:
		case 11:
			m_aprilTagHeight = reef;
			break;

		case 12:
		case 13:
			m_aprilTagHeight = coralStation;
			break;

		case 14:
		case 15:
			m_aprilTagHeight = barge;
			break;

		case 16:
			m_aprilTagHeight = processor;
			break;

		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
			m_aprilTagHeight = reef;
			break;

		default:
			break;
		}

		return 	m_aprilTagHeight;
	}

	std::string AprilTag::GetAprilTagGameLocation() // UPDATE EACH GAME SEASON
	{
		// Grab apriltag game location name.

		// Variables.
		std::string coralStation = "Coral Station";
		std::string processor = "Processor";
		std::string reef = "Reef";
		std::string barge = "Barge";

		// Set game location name depending on ID.
		switch (m_aprilTagID)
		{
		case 1:
		case 2:
			m_aprilTagGameLocation = coralStation;
			break;

		case 3:
			m_aprilTagGameLocation = processor;
			break;

		case 4:
		case 5:
			m_aprilTagGameLocation = barge;
			break;

		case 6:
		case 8:
		case 9:
		case 10:
		case 11:
			m_aprilTagGameLocation = reef;
			break;

		case 12:
		case 13:
			m_aprilTagGameLocation = coralStation;
			break;

		case 14:
		case 15:
			m_aprilTagGameLocation = barge;
			break;

		case 16:
			m_aprilTagGameLocation = processor;
			break;

		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
			m_aprilTagGameLocation = reef;
			break;

		default:
			break;
		}

		return 	m_aprilTagGameLocation;
	}
}
