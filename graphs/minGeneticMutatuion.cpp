/*
@author github.com/iitzmahi
*/
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet;
        for (auto b : bank) {
            bankSet.insert(b);
        }
        if (bankSet.find(endGene) == bankSet.end())
            return -1;
        queue<pair<string, int>> q;
        unordered_set<string> vis;
        q.push({startGene, 0});
        vis.insert(startGene);
        while (!q.empty()) {
            pair<string, int> curr = q.front();
            q.pop();
            if (curr.first == endGene)
                return curr.second;
            for (int i = 0; i < 9; i++) {
                char org = curr.first[i];
                curr.first[i] = 'A';
                if (vis.find(curr.first) == vis.end() &&
                    bankSet.find(curr.first) != bankSet.end()) {
                    vis.insert(curr.first);
                    q.push({curr.first, curr.second + 1});
                }
                curr.first[i] = 'C';
                if (vis.find(curr.first) == vis.end() &&
                    bankSet.find(curr.first) != bankSet.end()) {
                    vis.insert(curr.first);
                    q.push({curr.first, curr.second + 1});
                }
                curr.first[i] = 'G';
                if (vis.find(curr.first) == vis.end() &&
                    bankSet.find(curr.first) != bankSet.end()) {
                    vis.insert(curr.first);
                    q.push({curr.first, curr.second + 1});
                }
                curr.first[i] = 'T';
                if (vis.find(curr.first) == vis.end() &&
                    bankSet.find(curr.first) != bankSet.end()) {
                    vis.insert(curr.first);
                    q.push({curr.first, curr.second + 1});
                }
                curr.first[i] = org;
            }
        }
        return -1;
    }
};
