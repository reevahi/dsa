/*
@author github.com/iitzmahi
Here we can do this question in many ways, such that we can take a dummy matrix and then fill it
and return it but that will take a space complexity of O(N^2)
We can optimize this by taking two vectors of int type of size n (for marking 0 in rows) and m (for marking 0 for column)
here we reduced the S.C. to O(N)
we can further optimize it to take O(1) constant S.C., by using the Oth row and column, but we just have to
take care for the (0,0) cell as it will be common for both the 0th row and col, so because of that we can
get false result, to marke that column we will use a flag variable
link: https://leetcode.com/problems/spiral-matrix/
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = false;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0 ;i <rows;i++){
            if(matrix[i][0]==0) col0 = true;
            for(int j = 1 ; j < cols ; j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }

        for(int i = rows-1 ; i>=0 ; i--){
            for(int j = cols-1; j>=1 ;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col0) matrix[i][0] = 0;
        }
    }
};