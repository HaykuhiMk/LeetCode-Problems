/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example:
Input: root = [1,2,2,3,4,4,3]
Output: true
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
    bool cmp(TreeNode* node1, TreeNode* node2)
    {
        if (node1 == nullptr && node2 == nullptr)
        {
            return true;
        }
        if (node1 == nullptr || node2 == nullptr)
        {
            return false;
        } 
        return (node1->val == node2->val) && cmp(node1->left, node2->right) && cmp(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return cmp(root, root);
    }
};
