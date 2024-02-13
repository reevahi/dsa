/*
@author github.com/iitzmahi
We just have to check whether we have gotten the same number while checking it
for a happy number.
*/
class Solution {
public:
    set<int> s;
    bool isHappy(int n) {
        if (n == 1 || n == 7)
            return true;
        if (n <= 9)
            return false;
        if (s.find(n) == s.end()) {
            s.insert(n);
            int newNumber = 0;
            while (n != 0) {
                newNumber += (n % 10) * (n % 10);
                n /= 10;
            }
            return isHappy(newNumber);
        } else
            return false;
    }
};