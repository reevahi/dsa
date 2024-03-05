/*
@author github.com/iitzmahi
*/


class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    void dfs(vector<vector<char>>& board, int i, int j) {
        int row = board.size();
        int col = board[0].size();
        if (board[i][j] == 'O') {
            board[i][j] = '@';
            for (int z = 0; z < 4; z++) {
                int newRow = i + dx[z];
                int newCol = j + dy[z];
                if (newRow >= 0 && newRow < row && newCol >= 0 &&
                    newCol < col && board[newRow][newCol] != 'X' &&
                    board[newRow][newCol] != '@') {
                    dfs(board, newRow, newCol);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
                    dfs(board, i, j);
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '@') {
                    board[i][j] = 'O';
                } else
                    board[i][j] = 'X';
            }
        }
    }
};