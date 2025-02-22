#pragma once
#include <iostream>
#include <string>
#include <units/angle.h>
#include <units/length.h>
#include <frc/smartdashboard/SmartDashboard.h>

namespace Robot2025
{

struct AprilTag 
{
    public:
    	// Setter Functions:
		void SetID(const int& aprilTagID);
		void SetDistance(const double& aprilTagDist);
        void SetHeight(const double& aprilTagHeight);
        void SetYaw(const int& aprilTagYaw);
		void SetPitch(const double& aprilTagPitch);
        void SetSkew(const double& aprilTagSkew);
        void SetGameLocation(const std::string& aprilTagGameLocation);

        // Get Data Functions:
        int GetID();
        double GetDistMeters();
        double GetHeightMeters();
        double GetYawDegrees();
        double GetPitchDegrees();
        double GetSkewDegrees();
        std::string GetGameLocation();

	private:
		// Variables:
		int m_aprilTagID = 0;
		double m_aprilTagDist = 0.0;
		double m_aprilTagHeight = 0.0;
        double m_aprilTagYaw = 0.0;
        double m_aprilTagPitch = 0.0;
        double m_aprilTagSkew = 0.0;
		std::string m_aprilTagGameLocation = " ";
};

}
