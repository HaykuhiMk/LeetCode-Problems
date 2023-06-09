/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> map;
        int maxLen = 0;
        int left = 0;
        int right = 0;
        while (right < s.size())
        {
            if (map.count(s[right]) == 0)
            {
                map.insert({s[right], 1});
                maxLen = std::max(maxLen, right - left + 1);
                ++right;
            }
            else
            {
                map.erase(s[left]);
                ++left;
            }
        }
        return maxLen;
    }
};
