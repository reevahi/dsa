/**
@author github.com/iitzmahi
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode* templ = lowestCommonAncestor(root->left, p, q);
        TreeNode* tempr = lowestCommonAncestor(root->right, p, q);
        if (templ != NULL && tempr != NULL)
            return root;
        else if (templ)
            return templ;
        else if (tempr)
            return tempr;
        else
            return NULL;
    }
};