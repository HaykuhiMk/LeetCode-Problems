/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
If the tree has more than one mode, return them in any order.
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [1,null,2,2]
Output: [2]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderTraversal(TreeNode* root, std::vector<int>& vc) 
    {
        if (root == nullptr) 
        {
            return;
        }
        inorderTraversal(root->left, vc);
        vc.push_back(root->val);
        inorderTraversal(root->right, vc);
    }

    std::vector<int> findMode(TreeNode* root) 
    {
        std::vector<int> vec;
        inorderTraversal(root, vec);
        std::map<int, int> count;
        for (const auto& num : vec) 
        {
            count[num]++;
        }
        int maxFreq = std::numeric_limits<int>::min();
        for (const auto& pair : count) 
        {
            if (pair.second > maxFreq) 
            {
                maxFreq = pair.second;
            }
        }
        std::vector<int> modes;
        for (const auto& pair : count) 
        {
            if (pair.second == maxFreq) 
            {
                modes.push_back(pair.first);
            }
        }
        if (modes.empty()) 
        {
            modes.push_back(0);  
        }
        return modes;
    }
};
