/* Copyright 2016 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/units/cmath.hpp>
#include <boost/units/io.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/systems/cgs/length.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/quantity.hpp>
#include <iostream>

int main()
{
  using boost::units::quantity;
  using boost::units::degree::degree;
  using boost::units::cgs::centimeter;
  using namespace boost::units::si;

  const auto                 g=9.8*meter_per_second_squared;
  const quantity<length>     l{50.0*centimeter};
  const auto                 dt=0.02*second;

  quantity<plane_angle>      theta{30.0*degree};
  quantity<angular_velocity> theta_v;
  
  std::cout<<"time\tangle\n";
  for(auto t=0.0*second;t<2.0*second;t+=dt){
    auto theta_a=-sin(theta)*radian*g/l;
    theta_v+=theta_a*dt;
    theta+=theta_v*dt;
    std::cout<<t<<"\t"<<quantity<boost::units::degree::plane_angle>{theta}<<"\n";
  }
}
