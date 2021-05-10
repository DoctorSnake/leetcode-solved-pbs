/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/
#include <vector>
#include <iostream>

using namespace std;

//vector<vector<int>> threeSum(vector<int>& nums) {
    
//}

template <typename Iter>
void print_container (Iter it, Iter end) {
  cout << "[";
  for (; it!=end; ++it) 
  {
    cout << *it << " ";
    if(it != end-1) cout << ", ";
  }
  cout << "]"<< endl;
}

void test3Sum()
{

  vector<int> test_input =  {-1,0,1,2,-1,-4};
  // vector<vector<int>> test_output = threeSum(test_input);
  vector<vector<int>> test_output = { {-1,-1,2}, {-1,0,1}};
  cout << "input : "; 
  print_container(test_input.begin(), test_input.end());
  cout << "output: " << endl;
  for (auto v : test_output)
  {
    print_container(v.begin(), v.end());
  } 
  cout << " Expected output: [[-1,-1,2],[-1,0,1]]" << endl;
}
