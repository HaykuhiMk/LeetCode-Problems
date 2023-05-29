/*
Given an integer n, return the number of structurally unique BST's (binary search trees) 
which has exactly n nodes of unique values from 1 to n.

Example 1:
Input: n = 3
Output: 5
*/

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1)
        {
            return 1;
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
           res += numTrees(i - 1) * numTrees(n - i);
        } 
        return res;
    }
};
