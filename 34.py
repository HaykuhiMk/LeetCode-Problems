class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def findBound(isFirst) -> int:
            left = 0
            right = len(nums) - 1
            bound = -1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    bound = mid
                    if isFirst:
                        right = mid - 1
                    else:
                        left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return bound

        first = findBound(isFirst=True)
        if first == -1:
                return [-1, -1] 
        second = findBound(isFirst=False)
        return [first, second]

