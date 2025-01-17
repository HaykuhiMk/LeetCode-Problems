class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_dict = {}
        for i, num in enumerate(nums):
            needed = target - num
            if needed in nums_dict:
                return [nums_dict[needed], i]
            nums_dict[num] = i
        
