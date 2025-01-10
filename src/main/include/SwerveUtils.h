// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

class SwerveUtils 
{
 public:
  SwerveUtils();

  static double StepTowards(double _current, double _target, double _stepsize);
   
  static double StepTowardsCircular(double _current, double _target, double _stepsize);

  static double AngleDifference(double _angleA, double _angleB);
  
  static double WrapAngle(double _angle);
};


