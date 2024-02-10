/*
Here we can go with the approach of sliding window and track the progress with
the help of 2 maps
So we take a window of size = (No. of words) * length of the word
and then for each window of that size we check all the words are present or not
link: https://leetcode.com/problems/substring-with-concatenation-of-all-words
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp1, mp2;
        for (int i = 0; i < words.size(); i++) {
            mp1[words[i]]++;
        }
        vector<int> ans;
        int windowSize = words[0].length();
        int start = 0;
        int end = words.size() * words[0].length() - 1;
        for (int i = 0; i < s.length(); i++) {
            start = i;
            end = words.size() * words[0].length() + i - 1;
            if (end >= s.length())
                return ans;
            for (int j = 0; j < words.size(); j++) {
                string substring = s.substr(start, windowSize);
                if (mp1.find(substring) == mp1.end())
                    break;
                mp2[substring]++;
                start += windowSize;
            }
            if (mp1 == mp2)
                ans.push_back(i);
            mp2.clear();
        }
        return ans;
    }
};