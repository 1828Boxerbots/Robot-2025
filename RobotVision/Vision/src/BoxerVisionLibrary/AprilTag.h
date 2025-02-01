#pragma once
#include <iostream>
#include <string>

namespace BV
{
	struct AprilTag
	{
	public:
		// Setter Functions:
		void SetAprilTagID(const int& aprilTagID);
		void SetAprilTagDistance(const double& aprilTagDist);

		// Struct Functions:
		int  GetAprilTagID();
		double GetAprilTagDistanceMeters();
		double GetAprilTagHeightMeters();
		std::string GetAprilTagGameLocation();

	private:
		// Variables:
		int m_aprilTagID = 0;
		double m_aprilTagDist = 0.0;
		double m_aprilTagHeight = 0.0;
		std::string m_aprilTagGameLocation = " ";
	};
}