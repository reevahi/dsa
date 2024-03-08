/*
@author github.com/iitzmahi
*/

/*
@author github.com/iitzmahi
*/
class Solution {
    void dfs(vector<int> adj[], unordered_set<int>& vis,
             unordered_set<int>& path, int i, bool& cycle, stack<int>& st) {
        vis.insert(i);
        path.insert(i);
        for (auto x : adj[i]) {
            if (path.find(x) != path.end())
                cycle = true;
            if (vis.find(x) == vis.end()) {
                dfs(adj, vis, path, x, cycle, st);
            }
        }
        path.erase(i);
        st.push(i);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        unordered_set<int> vis, path;
        stack<int> st;
        bool cycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (vis.find(i) == vis.end()) {
                dfs(adj, vis, path, i, cycle, st);
            }
        }
        if (cycle) {
            return {};
        } else {
            vector<int> ans;
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
            return ans;
        }
    }
};