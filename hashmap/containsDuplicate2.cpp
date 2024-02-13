/*
@author github.com/iitzmahi
Here we just have to chech whether the current index number is already present
in the map or not if yes, then we calculate the diff and check the condition,
if satisfies we return true, else we update the entry in the map
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                if (i - m[nums[i]] <= k)
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};