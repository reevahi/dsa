class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // most optimal code
        // in place O(1) S.C.
        bool isColZero = false;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    if (i > 0)
                        matrix[i][0] = 0;
                    if (i == 0)
                        isColZero = true;
                }
            }
        }

        for (int i = matrix.size() - 1; i > 0; i--) {
            for (int j = matrix[0].size() - 1; j >= 0; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0  ) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (isColZero) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
    }
};