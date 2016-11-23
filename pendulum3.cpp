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

using boost::units::quantity;
using boost::units::degree::degree;
using boost::units::cgs::centimeter;
using namespace boost::units::si;

quantity<boost::units::si::acceleration> operator"" _m_s2(long double x)
{
  return double(x)*meter_per_second_squared;
}

quantity<boost::units::si::length> operator"" _cm(long double x)
{
  return quantity<boost::units::si::length>{double(x)*centimeter};
}

quantity<boost::units::si::time> operator"" _s(long double x)
{
  return double(x)*second;
}

quantity<boost::units::si::plane_angle> operator"" _deg(long double x)
{
  return quantity<boost::units::si::plane_angle>{double(x)*degree};
}

quantity<boost::units::si::angular_velocity> operator"" _deg_s(long double x)
{
  return quantity<boost::units::si::angular_velocity>{double(x)*degree/second};
}

int main()
{
  const auto g=9.8_m_s2;
  const auto l=50.0_cm;
  const auto dt=0.02_s;

  auto       theta=30.0_deg;
  auto       theta_v=0.0_deg_s;
  
  std::cout<<"time\tangle\n";
  for(auto t=0.0_s;t<2.0_s;t+=dt){
    auto theta_a=-sin(theta)*radian*g/l;
    theta_v+=theta_a*dt;
    theta+=theta_v*dt;
    std::cout<<t<<"\t"<<quantity<boost::units::degree::plane_angle>{theta}<<"\n";
  }
}
