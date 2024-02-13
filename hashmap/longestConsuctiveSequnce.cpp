/*
@author github.com/iitzmahi
Here we put every element in a unordered_set and then we check via a forloop
how much longest consecutive sequence we can make.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> numSet;
        for (int i = 0; i < nums.size(); i++) {
            numSet.insert(nums[i]);
        }
        int maxLength = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (numSet.find(nums[i] - 1) == numSet.end()) {
                int count = 1;
                int num = nums[i] + 1;
                while (numSet.find(num) != numSet.end()) {
                    count++;
                    num++;
                }
                if (count > maxLength)
                    maxLength = count;
            }
        }
        return maxLength;
    }
};