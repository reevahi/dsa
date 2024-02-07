/*
Brute force is to go like
i = 0 --> n-1
    j = i+1 --> n-1
        calculate area and maximize it
Optimal approach will be 2 pointers where we have to put 1 pointer at start and
other pointer at n-1 then we calculate the are for that and we move that pointer
which has minimum height of the two link:
https://leetcode.com/problems/container-with-most-water/
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxArea = 0;
        while (i < j) {
            int mini = min(height[i], height[j]);
            maxArea = max(maxArea, (j - i) * mini);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
};