/*
@author github.com/iitzmahi
Here we just have to traverse the whole matrix and just set 1 to 2 if we have to update it to 0
and 0 to -1 if we have to set it to 1, after checking all the conditions, which will be applied after
checking how many neighbours around it are alive
link: https://leetcode.com/problems/game-of-life/
*/
class Solution {
public:
    void needToChange(vector<vector<int>>& board, int i,int j,int rows,int cols){
        int live =0;
        if((i-1)>=0 && (j-1)>=0 && (i-1)<=rows && (j-1)<=cols){
            if(board[i-1][j-1]==1 || board[i-1][j-1]==2)
            live++;
        }
        if(i>=0 && (j-1)>=0 && i<=rows && (j-1)<=cols){
            if(board[i][j-1]==1 || board[i][j-1]==2)
            live++;
        }
        if((i+1)>=0 && (j-1)>=0 && (i+1)<=rows && (j-1)<=cols){
            if(board[i+1][j-1]==1 || board[i+1][j-1]==2)
            live++;
        }
        if((i-1)>=0 && (j)>=0 && (i-1)<=rows && (j)<=cols){
            if(board[i-1][j]==1 || board[i-1][j]==2)
            live++;
        }
        if((i+1)>=0 && (j)>=0 && (i+1)<=rows && (j)<=cols){
            if(board[i+1][j]==1 || board[i+1][j]==2)
            live++;
        }
        if((i-1)>=0 && (j+1)>=0 && (i-1)<=rows && (j+1)<=cols){
            if(board[i-1][j+1]==1 || board[i-1][j+1]==2)
            live++;
        }
        if((i)>=0 && (j+1)>=0 && (i)<=rows && (j+1)<=cols){
            if(board[i][j+1]==1 || board[i][j+1]==2)
            live++;
        }
        if((i+1)>=0 && (j+1)>=0 && (i+1)<=rows && (j+1)<=cols){
            if(board[i+1][j+1]==1 || board[i+1][j+1]==2)
            live++;
        }

        if(board[i][j]==0 && live == 3){
            board[i][j]=-1;
        }
        else if(board[i][j]==1 && live < 2) board[i][j]=2;
        else if(board[i][j]==1 && live >3) board[i][j]=2;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size()-1;
        int cols = board[0].size()-1;
        for(int i=0;i<=rows;i++){
            for(int j=0;j<=cols;j++){
                needToChange(board,i,j,rows,cols);
            }
        }
        for(int i=0;i<=rows;i++){
            for(int j=0;j<=cols;j++){
                if(board[i][j]==2)
                board[i][j]=0;
                else if(board[i][j]==-1)
                board[i][j]=1;
            }
        }
    }
};