class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // For this problem we have to get sum for every possible subarray
        //and then find out the maximum of it, so bascially that will be 2
        //nested loops one from 1--->N-1 and then inned will be from
        //i--->n-1; for this the T.C. will be O(N^3) and with a few tweaks it will
        //be O(N^2)
        //Now for kadane algorithm we say that if the sum is getting -ve we dont consider it and make the
        //sum 0 and update the max accordingly
        
        int maxSum = nums[0];
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(maxSum < sum) maxSum = sum;
            if(sum < 0) sum =0;
        }
        return maxSum;
    }
};