/*
@author github.com/iitzmahi
*/
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        while (l <= r) {
            long mid = (l + r) / 2;
            if ((mid * mid) > x) {
                r = mid - 1;
            } else if ((mid * mid) < x) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return r;
    }
};