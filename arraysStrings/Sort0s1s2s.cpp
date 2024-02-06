class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Brute is to just sort it using merge sort which will use O(NlogN) and space O(N)
        //Optimal which runs in O(N) is solved using Dutch National Flag Algorithm, that uses 3
        //pointers
        // 1st pointer low will have all the 0s to the left of it so 0-->low-1 will be all 0
        // 2nd pointer mid will have all the 1s to the left of it upto low so low-->mid-1 will be 1
        // 3rd pointer high will have all random unsorted element i.e, mid-->high will be all unsorted elements
        // finally high+1-->n-1 will be all 2s
        //link https://leetcode.com/problems/sort-colors/description/
        int low,mid,high;
        low = mid = 0;
        high = nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++; mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};