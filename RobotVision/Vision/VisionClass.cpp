//#include "VisionClass.h"
//
//VisionClass::VisionClass(int camID)
//{
//	// Set parameters to member varables for the class.
//	m_camID = camID
//}
//
//VisionClass::~VisionClass()
//{
//	// Release the camera and other running OpenCV sources when class is completed.
//	cap.Release();
//}
//
//void VisionClass::Init()
//{
//	// Grab video from camera.
//	cap.Open(m_camID);
//
//	// Check if camera is streaming.
//	if (!cap.isOpened())
//	{
//		std::cout << "Could not open the camera stream." << std::endl;
//		return;
//	}
//}
//
//void VisionClass::ProcessImage()
//{
//	int frameWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
//
//	cv::Mat frame;
//
//	cap >> frame;
//
//	if (frame.empty())
//	{
//		std::cerr << "ERROR: Could not read a frame." << std::endl;
//		break;
//	}
//
//	cv::Mat processed;
//	std::vector<int> markerIds;
//	std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
//	cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
//	cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_APRILTAG_36h11);
//	cv::aruco::ArucoDetector detector(dictionary, detectorParams);
//	detector.detectMarkers(frame, markerCorners, markerIds, rejectedCandidates);
//
//	processed = frame.clone();
//	cv::aruco::drawDetectedMarkers(processed, markerCorners, markerIds);
//
//	// Show the images
//	cv::imshow(unProcessedWindow, frame);
//	cv::imshow(processedWindow, processed);
//
//	if (cv::waitKey(1) == 'q')
//	{
//		break;
//	}
//}
//
//int VisionClass::GetAprilTagID()
//{
//
//}
//
//double VisionClass::GetAprilTagDistance()
//{
//
//}
//
//double VisionClass::GetAprilTagHeight()
//{
//
//}