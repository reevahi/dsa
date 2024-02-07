/*
1. We can add the second array after m elements in first array and then sort it
2. We can use gap method and then we can just put all element of nums2 after m elements of nums1
3. (Most optimal) We can take 2 pointers each at the last element of both array i.e, for nums1 = m-1 and for
nums2 = n-1, after this we simply put the bigger element from nums1[i] and nums2[j] ----> nums1[m+n-1]
This will give the total T.C. of O(n+m) and S.C as O(1)
link: https://leetcode.com/problems/merge-sorted-array/
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        int i = m-1;
        int j = n-1;
        if(i<0){
            while(j>=0){
                nums1[j]=nums2[j];
                j--;
            }
        }
        else{
            while(i>=0 && j>=0){
                if(nums1[i]>=nums2[j]){
                    nums1[k]=nums1[i];
                    k--;i--;
                }
                else{
                    nums1[k]=nums2[j];
                    k--;j--;
                }
            }
            while(i>=0){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            while(j>=0){
                nums1[k]=nums2[j];
                j--;k--;
            }
        }
    }
};