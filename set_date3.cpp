/* Copyright 2016 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>

struct month{int value;};
struct day{int value;};
struct year{int value;};

void set_date(month m,day d,year y)
{
  static const char* month_names[]=
  {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Dec"};

  std::cout<<month_names[m.value-1]<<" "<<d.value<<", "<<y.value<<"\n";
}

int main()
{
  // Apr 12, 1961: first spaceflight by Gagarin
  set_date(month{4},day{112},year{1961}); // oops
}
