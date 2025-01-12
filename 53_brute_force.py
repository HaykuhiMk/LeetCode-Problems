class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = float('-inf') 
        size = len(nums)
        for i in range(size):
            curr_sum = 0
            for j in range(i, size):
                curr_sum += nums[j]
                max_sum = max(max_sum, curr_sum)
        return max_sum
        
