/*
@author github.com/iitzmahi
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> dictionary;
        for (auto word : wordList) {
            dictionary.insert(word);
        }
        if (dictionary.find(endWord) == dictionary.end())
            return 0;
        int len = beginWord.length();
        unordered_set<string> vis;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        vis.insert(beginWord);
        while (!q.empty()) {
            pair<string, int> curr = q.front();
            if (curr.first == endWord)
                return curr.second;
            q.pop();
            for (int i = 0; i < len; i++) {
                char org = curr.first[i];
                for (int j = 0; j < 26; j++) {
                    curr.first[i] = 'a' + j;
                    if ((dictionary.find(curr.first) != dictionary.end()) &&
                        (vis.find(curr.first) == vis.end())) {
                        q.push({curr.first, curr.second + 1});
                        vis.insert(curr.first);
                    }
                }
                curr.first[i] = org;
            }
        }
        return 0;
    }
};