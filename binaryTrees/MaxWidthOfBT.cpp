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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long int>> q;
        q.push(make_pair(root, 0));
        int maxWidth = 0;
        while (!q.empty()) {
            int counter = q.size();
            long int minus = q.front().second;
            long int start, end;
            for (int i = 0; i < counter; i++) {
                TreeNode* temp = q.front().first;
                long int index = q.front().second;
                q.pop();
                if (i == 0) {
                    start = index;
                }
                end = index;
                index = index - minus;
                if (temp->left != NULL) {
                    q.push(make_pair(temp->left, 2 * index + 1));
                }
                if (temp->right != NULL) {
                    q.push(make_pair(temp->right, 2 * index + 2));
                }
            }
            maxWidth = max(maxWidth, (int)(1 + end - start));
        }
        return maxWidth;
    }
};