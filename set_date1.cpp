/* Copyright 2016 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>

void set_date(int month,int day,int year)
{
  static const char* month_names[]=
  {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Dec"};

  std::cout<<month_names[month-1]<<" "<<day<<", "<<year<<"\n";
}

int main()
{
  // man lands on Moon
  set_date(20,7,1969); // oops
}
