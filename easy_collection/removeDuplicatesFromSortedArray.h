/*Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
It doesn't matter what you leave beyond the returned length.

Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]
Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively. 
It doesn't matter what values are set beyond the returned length. 
*/

/*
#include <algorithm>

int removeDuplicates(vector<int>& nums) {
  if(nums.size() == 0) return 0;
  int j = 1;
  while (j <= nums.size()-1)
  {
      bool found_duplicate = true;
      while(found_duplicate)
      {
          // search for the element nums[j] in the sub array from 0 to j-1
          auto it = std::find(nums.begin(), nums.begin()+j-1, nums[j]);
          found_duplicate = (*it == nums[j]);
          if(found_duplicate){
              // erase the duplicate if found
              nums.erase(it);
              // decrement j to stay on the same element
              j--;
          }
          if(j == 0){
              // j reaches 0 then there is no other element
              found_duplicate = false;
          }
      }
      j++;
  }
  int size = nums.size();
  return size;
}
*/

// Another Solution 

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int>::iterator it = nums.end()-1;
    while (it > nums.begin()){
        int j = *it;
        int k = *(it-1);
        if (j == k) {
            nums.erase(it);
            n--;
        }
        it--;
    }
    return n; 
}