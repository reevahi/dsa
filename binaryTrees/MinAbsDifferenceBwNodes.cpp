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
 * right(right) {}
 * };
 */
class Solution {
    int minAbsDiff = INT_MAX;
    int prev = -1;
    void getMinimumDifferenceHelper(TreeNode* root) {
        if (root == NULL)
            return;
        getMinimumDifferenceHelper(root->left);
        if (prev != -1) {
            minAbsDiff = min(minAbsDiff, abs(root->val - prev));
        }
        prev = root->val;
        getMinimumDifferenceHelper(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        getMinimumDifferenceHelper(root);
        return minAbsDiff;
    }
};