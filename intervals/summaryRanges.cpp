/*
@author github.com/iitzmahi
Here we maintain 2 pointers and check whether an element greater than
the current one exists and then update the ans string accordingly
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        int i, j;
        i = j = 0;
        vector<string> ans;
        while (j < nums.size() - 1) {
            if ((long int)nums[j + 1] - nums[j] == 1) {
                j++;
            } else {
                if (i == j) {
                    ans.push_back(to_string(nums[i]));
                    i++;
                    j++;
                } else {
                    ans.push_back(to_string(nums[i]) + "->" +
                                  to_string(nums[j]));
                    j++;
                    i = j;
                }
            }
        }
        if (i == j)
            ans.push_back(to_string(nums[i]));
        else
            ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
        return ans;
    }
};