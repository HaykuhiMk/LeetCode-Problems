/*
Given the root of a binary search tree and an integer k, return true if there exist two elements 
in the BST such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
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
    void inorderTraverse(std::vector<int>& vc, TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorderTraverse(vc, root->left);
        vc.push_back(root->val);
        inorderTraverse(vc, root->right);
    }

    bool findTarget(TreeNode* root, int k) 
    {
        std::vector<int> vc;
        inorderTraverse(vc, root);
        for (int i = 0; i < vc.size(); ++i)
        {
            for (int j = 0; j < vc.size(); ++j)
            {
                if (vc[i] + vc[j] == k && i != j)
                {
                    return true;
                }
                continue;
            }
        }
        return false;
    }
};
