/* Copyright 2016 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <cassert>
#include <iostream>
#include <limits>

template<
  typename Int,
  Int min=std::numeric_limits<Int>::min(),
  Int max=std::numeric_limits<Int>::max()
>
class range{
  Int value;
  void check()const{assert(value>=min&&value<=max);}
public:
  range(Int value):value{value}{check();}
  range& operator=(Int value){this->value=value;check();return *this;}
  operator Int()const{return value;}
};

struct month:range<int,1,12>{using range::range;};
struct day:range<int,1,31>{using range::range;};
struct year:range<int>{using range::range;};

void set_date(month m,day d,year y)
{
  static const char* month_names[]=
  {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Dec"};

  std::cout<<month_names[m]<<" "<<d<<", "<<y<<"\n";
}

int main()
{
  // March 31, 1966: Luna 10 probe is launched
  set_date(month{4},day{31},year{1966}); // oops
}
