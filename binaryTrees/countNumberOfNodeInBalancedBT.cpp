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
    int leftHeight(TreeNode* root) {
        TreeNode* temp = root;
        if (root == NULL)
            return 0;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->left;
        }
        return count;
    }
    int rightHeight(TreeNode* root) {
        TreeNode* temp = root;
        if (root == NULL)
            return 0;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->right;
        }
        return count;
    }

public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh = leftHeight(root->left);
        int rh = rightHeight(root->right);
        if (lh == rh)
            return pow(2, lh + 1) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};