/* Copyright 2016 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <cmath>
#include <iostream>

int main()
{
  const double g=9.8;   // m/s2
  const double l=50.0;  // cm
  const double dt=0.02; // s

  double theta=30.0;    // degrees
  double theta_v=0.0;   // degrees/s

  std::cout<<"time\tangle\n";
  for(double t=0.0;t<2.0;t+=dt){
    double theta_a=-sin(theta*2.0*3.14159265/360)*g/(l/100.0);
    theta_v+=theta_a*dt;
    theta+=theta_v*dt;
    std::cout<<t<<" s\t"<<theta<<" deg\n";
  }
}
