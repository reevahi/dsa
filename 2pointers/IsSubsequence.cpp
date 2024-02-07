/*
This will be solved using keeping 1 pointer at the start of subsequence and
check whether we can reach the end or not
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < t.length(); i++) {
            if (j >= s.length()) {
                return true;
            } else if (s[j] == t[i])
                j++;
        }
        if (j == s.length())
            return true;
        else
            return false;
    }
};