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
    int maxAns = INT_MIN;
    int maxPathSumHelper(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lsum = maxPathSumHelper(root->left);
        int rsum = maxPathSumHelper(root->right);
        maxAns = max(maxAns, lsum + rsum + root->val);
        int ans = root->val + max(lsum, rsum);
        if (ans <= 0)
            return 0;
        else
            return ans;
    }

public:
    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return maxAns;
    }
};