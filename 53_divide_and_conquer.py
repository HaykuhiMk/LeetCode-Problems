class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        def max_sub_helper(nums, left, right):
            if left == right:
                return nums[left]
            mid = left + (right - left) // 2  
            left_max = max_sub_helper(nums, left, mid)
            right_max = max_sub_helper(nums, mid + 1, right)
            max_sub = maxCrossingSum(nums, left, mid, right)
            return max(left_max, right_max, max_sub)
        
        def maxCrossingSum(nums, left, mid, right):
            left_sum = float('-inf')
            curr_sum = 0
            for i in range(mid, left - 1, -1):
                curr_sum += nums[i]
                left_sum = max(curr_sum, left_sum)

            right_sum = float('-inf')
            curr_sum = 0
            for i in range(mid + 1, right + 1):
                curr_sum += nums[i]
                right_sum = max(curr_sum, right_sum)
            
            return left_sum + right_sum

        return max_sub_helper(nums, 0, len(nums) - 1)
