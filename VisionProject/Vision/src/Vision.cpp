#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

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

		processed = frame.clone();
		cv::aruco::drawDetectedMarkers(processed, markerCorners, markerIds);

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