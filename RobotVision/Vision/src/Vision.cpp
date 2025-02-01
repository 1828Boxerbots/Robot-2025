#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/aruco.hpp>

#include "BoxerVisionLibrary/Camera.h"
#include "BoxerVisionLibrary/AprilTag.h"

int main()
{
	BV::Camera cam{0, (0.00508 / 2), "36h11"};
	cam.ProcessImageInit();

	while (true)
	{
		cam.ProcessImageAprilTag();

		if (cam.AprilTagsDataArray().size() > 0)
		{
			BV::AprilTag aprilTag = cam.AprilTagsData(0);
			std::cout << "AprilTag ID: " << aprilTag.GetAprilTagID() << std::endl;
			std::cout << "AprilTag Dist: " << aprilTag.GetAprilTagDistanceMeters() << std::endl;
			std::cout << "AprilTag Height: " << aprilTag.GetAprilTagHeightMeters() << std::endl;
			std::cout << "AprilTag Target Location: " << aprilTag.GetAprilTagGameLocation() << std::endl;
			std::cout << " " << std::endl;
		}
		else
		{
			std::cout << "No apriltags found." << std::endl;
		}

	}
}