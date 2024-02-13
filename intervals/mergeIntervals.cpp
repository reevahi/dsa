/*
@author github.com/iitzmahi
First we sort the 2-D array
Then we just iterate through the 2D array to check the ith and (i+1)th interval
can be merged or not If Yes then we merge them and make a new array If No, then
we push the array in our result 2D array
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};