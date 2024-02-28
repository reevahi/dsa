/**
@author github.com/iitzmahi
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
 * };
 */
class Solution {
    int prev;
    bool isPrevPresent = false;

public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        bool left = isValidBST(root->left);
        if (isPrevPresent) {
            if (prev >= root->val)
                return false;
        } else
            isPrevPresent = true;
        prev = root->val;
        bool right = isValidBST(root->right);
        return (left && right);
    }
};