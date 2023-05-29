/*
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file 
or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization
algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized
to the original tree structure. The encoded string should be as compact as possible.

Example 1:
Input: root = [2,1,3]
Output: [2,1,3]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    std::string serialize(TreeNode* root) 
    {
        return encode(root);
    }

    TreeNode* deserialize(const std::string& data) 
    {
        std::stringstream ss(data);
        std::string item;
        TreeNode* root = nullptr;
        while (getline (ss, item, ' ')) 
        {
            root = insert(root, stoi(item));
        }
        return root;
    }

    std::string encode(TreeNode* root) 
    {
        if (!root)
        {
            return "";
        }
        return to_string(root->val) + " " + encode(root->left) + encode(root->right);
    }
    
    TreeNode* insert(TreeNode* root, int val) 
    {
        if (root == nullptr) 
        {
			TreeNode* tmp = new TreeNode(val);
			return tmp;
		}
		if (val <= root->val)
        {
            root->left = insert(root->left, val);
        }
		else
        {
			root->right = insert(root->right, val);
        }
		return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
