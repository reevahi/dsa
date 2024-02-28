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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        bool leftToRight = true;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            TreeNode* temp;
            int counter = q.size();
            vector<int> ans1;
            for (int i = 0; i < counter; i++) {
                temp = q.front();
                if (leftToRight)
                    ans1.push_back(temp->val);
                else
                    ans1.insert(ans1.begin(), temp->val);
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            ans.push_back(ans1);
            if (leftToRight)
                leftToRight = false;
            else
                leftToRight = true;
        }
        return ans;
    }
};