/*
@author github.com/iitzmahi
*/
class Solution {
    void dfs(vector<int> adj[], unordered_set<int>& vis,
             unordered_set<int>& path, int i, bool& cycle) {
        vis.insert(i);
        path.insert(i);
        for (auto x : adj[i]) {
            if (path.find(x) != path.end())
                cycle = true;
            if (vis.find(x) == vis.end()) {
                dfs(adj, vis, path, x, cycle);
            }
        }
        path.erase(i);
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto x : prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        unordered_set<int> vis, path;
        bool cycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (vis.find(i) == vis.end()) {
                dfs(adj, vis, path, i, cycle);
            }
        }
        return !cycle;
    }
};