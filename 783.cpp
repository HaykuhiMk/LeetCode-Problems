/*
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1
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

    int minDiffInBST(TreeNode* root) {
        std::vector<int> vc;
        inorderTraverse(vc, root);
        std::vector<int> diffs;
        for (int i = 0; i < vc.size(); ++i)
        {
            for (int j = 0; j < vc.size(); ++j)
            {
                if (i != j && vc[i] - vc[j] > 0)
                {
                    diffs.push_back(vc[i] - vc[j]);
                }
                continue;
            }
        }
        int min = diffs[0];
        for (int i = 1; i < diffs.size(); ++i)
        {
            if (diffs[i] < min)
            {
                min = diffs[i];
            }
        }
        return min;
    }
};
