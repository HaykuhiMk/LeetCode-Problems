/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> tmpMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmpNum = target - nums[i];
            if (tmpMap.find(tmpNum) != tmpMap.end())
            {
                return {tmpMap[tmpNum], i};            
            }
            tmpMap[nums[i]] = i;
        }
        return {-1, -1};
    }
};
