#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/aruco.hpp>

#include "AprilTag.h"

namespace BV
{
	class Camera
	{
	public:
		// Constructor:
		Camera(int camID, double camRad, std::string aprilTagFamily);

		// Class Functions:
		void ProcessImageInit();
		void ProcessImageAprilTag();

		// Data Save Class Variables:
		AprilTag AprilTagsData(int member);
		std::vector<AprilTag> AprilTagsDataArray();

		// Destructor:
		~Camera();

	private:
		// Class Variables:
		cv::VideoCapture m_cap;
		cv::Mat m_camMatrix;
		cv::Mat m_distCoeffs;
		cv::Mat m_frame;
		int m_camID = -1;
		int m_tagFamily = 0;
		int m_frameWidth = 0;
		double m_tagLength = 0.0;
		double m_camRad = 0.0;
		std::string m_aprilTagFamily;

		// Data Save Class Variables:
		std::vector<AprilTag> m_aprilTags;
	};
}