class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        index_map = {restaurant: idx for idx, restaurant in enumerate(list1)}  
        min_sum = float('inf')
        result = []
        for idx2, restaurant in enumerate(list2):
            if restaurant in index_map:
                idx1 = index_map[restaurant]
                index_sum = idx1 + idx2
                if index_sum < min_sum:
                    min_sum = index_sum
                    result = [restaurant]
                elif index_sum == min_sum:
                    result.append(restaurant)
        return result
