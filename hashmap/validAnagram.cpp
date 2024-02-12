/*
@author github.com/iitzmahi
Here we just see that the frequency of all the chars are same in both the
strings
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        vector<int> f1(256, 0);
        vector<int> f2(256, 0);
        for (int i = 0; i < s.length(); i++) {
            f1[s.at(i)]++;
            f2[t.at(i)]++;
        }
        for (int i = 0; i < 256; i++) {
            if (f1[i] != f2[i])
                return false;
        }
        return true;
    }
};