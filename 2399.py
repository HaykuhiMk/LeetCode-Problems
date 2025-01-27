class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        seen = {}
        for i, char in enumerate(s):
            idx = ord(char) - ord('a') 
            if char in seen:
                if i - seen[char] - 1 != distance[idx]:
                    return False
            else:
                seen[char] = i
        return True
