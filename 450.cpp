/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly 
updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
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
    TreeNode* findMinNode(TreeNode* node) 
    {
        if (node == nullptr) 
        {
            return node;
        }
        if (node->left == nullptr) 
        {
            return node;
        }
        return findMinNode(node->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (root == nullptr) 
        {
            return nullptr;
        }
        if (key > root->val) 
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (key < root->val) 
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (!root->right && !root-> left) 
        {
            delete root;
            return nullptr;
        }
        if (!root->right) 
        {
            TreeNode* tmp = root->left;
            delete root;
            return tmp;
        }
        if (!root->left) 
        {
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        }
        const TreeNode* tmp = findMinNode(root->right);
        root->val = tmp->val;
        root->right = deleteNode(root->right, tmp->val);
        return root;
    }
};
