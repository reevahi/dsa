class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakIndex = -1;
        for(int i = nums.size()-2; i>=0 ;i--){
            if(nums[i]<nums[i+1]){
                breakIndex = i;
                break;
            }
        }

        if(breakIndex == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = nums.size()-1; i > breakIndex; i--){
            if(nums[i]> nums[breakIndex])
            {
                swap(nums[i],nums[breakIndex]);
                break;
            }
        }

        reverse(nums.begin() + breakIndex +1, nums.end());
    }
};