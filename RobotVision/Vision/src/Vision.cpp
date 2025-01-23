#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/aruco.hpp>

//#include "VisionClass.h"
//
//int main()
//{
//	return 0;
//}

int main()
{
	// Grab video from camera.
	cv::VideoCapture cap(0);

	// Check if camera is streaming.
	if (!cap.isOpened())
	{
		std::cout << "Couldn't open the camera stream." << std::endl;
		return -1;
	}

	// Create a new window with the associated name
	std::string unProcessedWindow = "Live Feed: Default Cam";
	cv::namedWindow(unProcessedWindow);

	std::string processedWindow = "Processed Image";
	cv::namedWindow(processedWindow);

	int frameWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	double markerSize = 0.165; //Meters.
	//cv::calibrateCamera()

	const double camRad = .00508 / 2;
	cv::Mat camMatrix = (cv::Mat_<double>(3, 3) << (-camRad / 2), 0, 0, 0, (-camRad / 2), 0, 0, 0, 1);
	cv::Mat distCoeffs = cv::Mat::zeros(5, 1, CV_64F);
	cv::Mat frame;

	while (true)
	{
		cap >> frame;

		if (frame.empty())
		{
			std::cerr << "ERROR: Could not read a frame" << std::endl;
			break;
		}

		cv::Mat processed;
		std::vector<int> markerIds;
		std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
		cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
		cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_APRILTAG_36h11);
		cv::aruco::ArucoDetector detector(dictionary, detectorParams);
		detector.detectMarkers(frame, markerCorners, markerIds, rejectedCandidates);

		std::vector<cv::Vec3d> rotVecs, transVecs;
		cv::aruco::estimatePoseSingleMarkers(markerCorners, markerSize, camMatrix, distCoeffs, rotVecs, transVecs);

		processed = frame.clone();
		cv::aruco::drawDetectedMarkers(processed, markerCorners, markerIds);

		for (int id : markerIds) 
		{
			std::cout << "Detected marker ID: " << id << std::endl; //Displays ID
		}

		// Calculate distance
		if (transVecs.size() != 0)
		{
			for (auto dist : transVecs)
			{
				double distance = cv::norm(dist); // Assuming only one marker detected
				std::cout << "Distance: " << distance << " meters" << std::endl;
			}
		}

		// Show the images
		cv::imshow(unProcessedWindow, frame);
		cv::imshow(processedWindow, processed);

		if (cv::waitKey(1) == 'q')
		{
			break;
		}
	}

	cap.release();
	cv::destroyAllWindows();

	return 0;
}