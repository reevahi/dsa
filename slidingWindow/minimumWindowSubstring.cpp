/*
Here we check that all the letters in the given string are present int the
big string or not, so for this we use the same concept as in minimumsizesubarraysum problem
link: https://leetcode.com/problems/minimum-window-substring
*/

class Solution {
public:
    bool map2greaterthanorequalmap1(unordered_map<char, int>& m1,
                                    unordered_map<char, int>& m2) {
        for (const auto& pair : m1) {
            if (m2[pair.first] < m1[pair.first])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }
        if (s.length() < t.length())
            return "";
        if (s == t)
            return t;
        int start = 0;
        int subStrStart = 0;
        int subStrEnd = 0;
        int diff = INT_MAX;
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < t.length(); i++) {
            mp1[t[i]]++;
        }
        for (int i = 0; i < s.length(); i++) {
            mp2[s[i]]++;
            while (map2greaterthanorequalmap1(mp1, mp2)) {
                if (diff > (i - start + 1)) {
                    diff = i - start + 1;
                    subStrStart = start;
                    subStrEnd = i;
                }
                mp2[s[start]]--;
                start++;
            }
        }
        if (diff == INT_MAX)
            return "";
        else
            return s.substr(subStrStart, subStrEnd - subStrStart + 1);
    }
};

