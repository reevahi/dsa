/*
Here the best optimal approach would be to just keep a hashmap that stores
the char and its recent index and check whethe the current element is present in
the index or not
T.C. --> O(N) S.C. --> O(N)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int start = 0;
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                maxLength = max(maxLength, (i - start + 1));
            } else {
                if (start > mp[s[i]]) {
                    maxLength = max(maxLength, (i - start + 1));
                } else {
                    start = mp[s[i]] + 1;
                }
            }
            mp[s[i]] = i;
        }
        return maxLength;
    }
};