/* Copyright 2016 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

void set_date(date d)
{
  std::cout<<d<<"\n";
}

int main()
{
  // March 31, 1966: Luna 10 probe is launched
  set_date({greg_year{1966},greg_month{4},greg_day{31}}); // throws
}
