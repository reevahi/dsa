/*
@author github.com/iitzmahi
Here we just have to check where the interval to insert fits, since all
intervals are mutually exclusive until unless we have merged the new interval,
after that normal flow will happen, before that we just have to check is that
interval is getting merged or not
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool isMerged = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (isMerged) {
                if (ans.back()[1] >= intervals[i][0]) {
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                } else {
                    ans.push_back(intervals[i]);
                }
            } else {
                if (newInterval[0] > intervals[i][1]) {
                    ans.push_back(intervals[i]);
                } else if (newInterval[1] < intervals[i][0]) {
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                    isMerged = true;
                } else {
                    newInterval[0] = min(newInterval[0], intervals[i][0]);
                    newInterval[1] = max(newInterval[1], intervals[i][1]);
                    ans.push_back(newInterval);
                    isMerged = true;
                }
            }
        }
        if (!isMerged) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};