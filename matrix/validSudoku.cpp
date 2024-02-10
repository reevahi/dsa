/*
@author github.com/iitzmahi
This problem can be solved by maintaining a set for each row and columns and also for
each 3 x 3 square, by doing this we just have to traverse the 2d array(matrix) once and
then check for any (i,j) that the ith rowset and jth columnset and also (i,j) pair squareset
has that value or not,  T.C. --> O(N^2), S.C. O(1)
link: https://leetcode.com/problems/valid-sudoku/
*/

class Solution {
public:
    int find3by3square(pair<int, int> p) {
        if (p == make_pair(0, 0))
            return 0;
        else if (p == make_pair(0, 1))
            return 1;
        else if (p == make_pair(0, 2))
            return 2;
        else if (p == make_pair(1, 0))
            return 3;
        else if (p == make_pair(1, 1))
            return 4;
        else if (p == make_pair(1, 2))
            return 5;
        else if (p == make_pair(2, 0))
            return 6;
        else if (p == make_pair(2, 1))
            return 7;
        else
            return 8;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rowset(9);
        vector<set<char>> colset(9);
        vector<set<char>> squareset(9);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.')
                    continue;
                if ((rowset[i].find(board[i][j]) != rowset[i].end()) ||
                    (colset[j].find(board[i][j]) != colset[j].end()) ||
                    (squareset[find3by3square(make_pair(i / 3, j / 3))].find(
                         board[i][j]) !=
                     squareset[find3by3square(make_pair(i / 3, j / 3))].end()))
                    return false;
                else {
                    rowset[i].insert(board[i][j]);
                    colset[j].insert(board[i][j]);
                    squareset[find3by3square(make_pair(i / 3, j / 3))].insert(
                        board[i][j]);
                }
            }
        }
        return true;
    }
};