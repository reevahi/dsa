/*
@author github.com/iitzmahi
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q(nums.begin(),
                                                         nums.begin() + k);
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > q.top()) {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};