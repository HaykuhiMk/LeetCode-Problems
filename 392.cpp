/*
Is Subsequence

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        std::string tmp;   
        int ind = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = ind; j < t.length(); ++j)
            {
                if (s[i] == t[j])
                {
                    tmp += t[j];
                    ind = j + 1;
                    break;
                }  
            }
        }
        return tmp == s;
    }
};
