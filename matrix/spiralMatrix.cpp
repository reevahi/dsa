/*
@author github.com/iitzmahi
Here we can see that we have to print the spiral traversal for the given n x m matrix
for this we have to go in the given order:
left-->right    top-->bottom    right-->left    bottom-->top
all in all we just have to take care of 2 edge cases:
1) where the matrix is a single row
2) where the matrix is a single column
link: https://leetcode.com/problems/spiral-matrix/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        vector<int> ans;
        while (top <= bottom && left <= right) {
            // left-->right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            // top-->bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            // right-->left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            // bottom-->top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return ans;
    }
};