/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
Example 1:

Input: nums = [2,2,1]
Output: 1

Example 2:

Input: nums = [4,1,2,1,2]
Output: 4

Example 3:

Input: nums = [1]
Output: 1

*/

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    sort(nums.begin(), nums.end());
    while(i < n-1){
        if(nums[i] == nums[i+1]){
            i += 2;
        }
        else{
            return nums[i];
        }
    }
    return nums[n-1];
}