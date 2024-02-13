/*
@author github.com/iitzmahi
Here we just have to find the overallping intervals b/w 2 intervals and
then if there is a overallping interval we dont increase the count of arrows
and if there is no overallping we have to increase the count of arrows
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1;
        vector<int> prev = points[0];
        for (int i = 1; i < points.size(); i++) {
            if (prev[1] < points[i][0]) {
                count++;
                prev = points[i];
            } else {
                prev[0] = max(prev[0], points[i][0]);
                prev[1] = min(prev[1], points[i][1]);
            }
        }
        return count;
    }
};