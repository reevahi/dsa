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
private:
    int sum = 0;

private:
    int ans = 0;

public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return ans;
        sum = sum * 10 + root->val;
        sumNumbers(root->left);
        sumNumbers(root->right);
        if (root->left == NULL && root->right == NULL) {
            ans = ans + sum;
            sum = sum / 10;
            return ans;
        }
        sum = sum / 10;
        return ans;
    }
};