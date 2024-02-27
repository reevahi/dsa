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
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            int temp = q.size();
            TreeNode* node;
            for (int i = 0; i < temp; i++) {
                node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};