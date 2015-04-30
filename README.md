# orocos_kinematics_dynamics
Orocos Kinematics and Dynamics C++ library

# Changed

1. velocityprofile_spline.cpp

### before
```c++
void VelocityProfile_Spline::SetProfileDuration(double pos1, double vel1, double acc1, double pos2, double vel2, double acc2, double duration)
{
  double T[6];

  generatePowers(5, duration, T);
  //...
```

###after
```c++
void VelocityProfile_Spline::SetProfileDuration(double pos1, double vel1, double acc1, double pos2, double vel2, double acc2, double duration)
{
  double T[6];
  duration_ = duration;
  generatePowers(5, duration, T);
  //...
```


