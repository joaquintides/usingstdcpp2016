/* Copyright 2016 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
class sorted_vector{
  using implementation=std::vector<T>;
  implementation impl;
public:
  using iterator=typename implementation::iterator;
  iterator begin(){return impl.begin();}
  iterator end(){return impl.end();}
  void insert(const T& x){impl.push_back(x);std::sort(begin(),end());}
  void erase(iterator it){impl.erase(it);}
  implementation extract(){return std::move(impl);}
  void accept(implementation&& i){impl=std::move(i);std::sort(begin(),end());}
};

template<typename Container>
void print(Container& c)
{
  for(const auto& x:c)std::cout<<x<<" ";
  std::cout<<"\n";
}

int main()
{
  sorted_vector<int> sv;
  for(int i=0;i<10;++i)sv.insert(i);
  print(sv);
  auto impl=sv.extract();
  for(std::size_t n=0,m=impl.size();n<m;++n)impl.push_back(impl[n]);
  sv.accept(std::move(impl));
  print(sv);
}
