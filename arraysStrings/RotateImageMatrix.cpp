/*
Here we can do this question using O(N^2) but in brute force where we have to make a new matrix
we will have to use the extra space of O(N^2)
Brute Force --> We first create a empty matrix of N x N
Then we traverse the original matrix each row one by one and then put newMatrix[j][n-1-i] = matrix[i][j]
Optimal --> We first transpose the matrix,
For this we just have to swap all the elements diagonally opp to each other,
Then we just reverse each row one by one
This will solve the matrix in place without taking extra space of O(N^2)
*/

class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j = i+1;j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void reverseMatrixRows(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            int n = matrix[0].size();
            for(int j =0;j<n/2;j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseMatrixRows(matrix);
        
    }
};