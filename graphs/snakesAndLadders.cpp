/*
@author github.com/iitzmahi
*/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int num = board.size();
        vector<pair<int, int>> coord(num * num + 1);
        bool reverse = false;
        int k = 1;
        for (int i = num - 1; i >= 0; i--) {
            for (int j = 0; j < num; j++) {
                if (reverse) {
                    coord[k] = {i, num - 1 - j};
                } else {
                    coord[k] = {i, j};
                }
                k++;
            }
            reverse = !reverse;
        }
        unordered_set<int> s;
        queue<pair<int, int>> q;
        q.push({1, 0});
        s.insert(1);
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            if (curr.first == num * num)
                return curr.second;
            for (int i = 1; i < 7; i++) {
                if ((curr.first + i) <= num * num) {
                    int r = coord[curr.first + i].first;
                    int c = coord[curr.first + i].second;
                    if (board[r][c] != -1) {
                        if (s.find(board[r][c]) == s.end()) {
                            s.insert(board[r][c]);
                            q.push({board[r][c], curr.second + 1});
                        }
                    } else {
                        if (s.find(curr.first + i) == s.end()) {
                            s.insert(curr.first + i);
                            q.push({(curr.first + i), curr.second + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};