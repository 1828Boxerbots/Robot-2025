#include "Camera.h"

namespace BV
{
	// Constructor:
	Camera::Camera(int camID, double camRad, std::string aprilTagFamily)
	{
		// Set parameters to member varables for the class.
		m_camID = camID;
		m_camRad = camRad;
		m_aprilTagFamily = aprilTagFamily;

		// Set camera ID.
		m_cap.open(m_camID);
	}

	// Class Functions:
	void Camera::ProcessImageInit()
	{
		// Check if camera is accessed.
		if (!m_cap.isOpened())
		{
			std::cerr << "ERROR: Camera is not opened." << std::endl;
			return;
		}

		// Define frame width.
		m_frameWidth = m_cap.get(cv::CAP_PROP_FRAME_WIDTH);

		// Define matrix variables for camera.
		m_camMatrix = (cv::Mat_<double>(3, 3) << (-m_camRad / 2), 0, 0, 0, (-m_camRad / 2), 0, 0, 0, 1);
		m_distCoeffs = cv::Mat::zeros(5, 1, CV_64F);
		m_frame;

		//Set up specifications for aptiltag family.
		if (m_aprilTagFamily == "36h11")
		{
			m_tagFamily = cv::aruco::DICT_APRILTAG_36h11;
			m_tagLength = 0.165;
			return;
		}
		else
		{
			std::cerr << "ERROR: Invalid apriltag type." << std::endl;
			return;
		}
	}

	void Camera::ProcessImageAprilTag()
	{
		// Checks if initialize function was called.
		if (m_frameWidth == 0.0)
		{
			std::cerr << "ERROR: ProcessImageAprilTag() is not initialized." << std::endl;
			return;
		}

		// Clear earlier apriltag data.
		m_aprilTags.clear();

		// Grab frame and check if frame is empty (to prevent errors).
		m_cap >> m_frame;

		if (m_frame.empty())
		{
			std::cerr << "ERROR: Could not read a frame." << std::endl;
			return;
		}

		// Define apriltag variables.
		std::vector<int> aprilTagID;
		std::vector<std::vector<cv::Point2f>> aprilTagCorners, rejectedCandidates;
		std::vector<cv::Vec3d> rotVecs, transVecs;

		// Define apriltag detector and find apriltag.
		cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
		cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(m_tagFamily);
		cv::aruco::ArucoDetector detector(dictionary, detectorParams);
		detector.detectMarkers(m_frame, aprilTagCorners, aprilTagID, rejectedCandidates);

		// Calculate distance and highlight apriltag markers found.
		cv::aruco::estimatePoseSingleMarkers(aprilTagCorners, m_tagLength, m_camMatrix, m_distCoeffs, rotVecs, transVecs);

		// Save apriltag IDs and distances if available.
		if (aprilTagID.size() != 0)
		{
			for (int i = 0; i < aprilTagID.size(); i++)
			{
				AprilTag curTag;
				curTag.SetAprilTagID(aprilTagID[i]);
				curTag.SetAprilTagDistance(cv::norm(transVecs[i]));

				m_aprilTags.push_back(curTag);
			}
			return;
		}
	}

	// Data Save Class Variables:
	AprilTag Camera::AprilTagsData(int member)
	{
		if (m_aprilTags.size() > 0)
		{
			return m_aprilTags[member];
		}
		else
		{
			std::cerr << "ERROR: No apriltag data." << std::endl;
			return AprilTag();
		}
	}

	std::vector<AprilTag> Camera::AprilTagsDataArray()
	{
		if (m_aprilTags.size() > 0)
		{
			return m_aprilTags;
		}
		else
		{
			std::cerr << "ERROR: No apriltag data." << std::endl;
			return std::vector<AprilTag>();
		}
	}

	// Destructor:
	Camera::~Camera()
	{
		// Release the camera and other running OpenCV sources when class is completed.
		m_cap.release();
	}
}