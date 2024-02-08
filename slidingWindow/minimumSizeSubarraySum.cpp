/*
This problem can be done optimally using sliding window approach
where we have to go on until the sum >= target
then we can remove an element only if that results in
sum to be still greater than or equal to target
link: https://leetcode.com/problems/minimum-size-subarray-sum/
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s =0;
        int minSize = INT_MAX;
        int count =0;
        for(int i=0;i<nums.length();i++){
            count+=nums[i];
            while(count >= target){
                minSize = min(minSize,(i-s+1));
                count-= nums[s];
                s++;
            }
        }
        return minSize == INT_MAX ? 0 : minSize;
    }
};