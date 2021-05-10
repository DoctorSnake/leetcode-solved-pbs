#include <iostream>
#include <list>

using namespace std;

/*
template <typename T>
void print_stl_data(const T& input)
{
  T::iterator it;
  for (it = input.begin(); it != input.end(); it++)
  {
    cout << *it;
    if (it != input.end()-1) cout <<", "; 
  }
  cout <<endl;
}
*/


void print_list(list<int> u){
  list<int>::iterator it;
  for (it =u.begin(); it != u.end(); it++){
    cout << *it <<" "; 
  }
  cout <<endl;
}