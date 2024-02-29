/*
@author github.com/iitzmahi
*/
class Solution {
    int binarySearch(vector<int>& nums, int target, int l, int r) {
        if (l > r) {
            return l;
        }
        int mid = (l + r) / 2;
        if (nums[mid] > target) {
            return binarySearch(nums, target, l, mid - 1);
        } else if (nums[mid] < target) {
            return binarySearch(nums, target, mid + 1, r);
        } else {
            return mid;
        }
    }

public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};