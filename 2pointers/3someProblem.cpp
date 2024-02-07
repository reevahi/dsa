/*
Brute force is to simply run 2 nested loops and check whether their sum is equal
to any number in the given array Optimal solution is that we have to sort the
array and then after that we have to run a loop i from i =0 --> i = n-1 then for
each i we run 2 pointers j--> 0  and k --> n-1; and run a while loop until (i<j)
then we check if the sum is small we increase j and decrease k if sum is larger
than required
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return result;
    }
};