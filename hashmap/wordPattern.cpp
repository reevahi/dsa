/*
@author github.com/iitzmahi
This is similar problem to that of isomorhic strings, same logic is applied here
We have just used istringstream to put the space seperated words in string to
form a vector of strings
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        istringstream iss(s);
        string word;
        while (iss >> word) {
            v.push_back(word);
        }
        unordered_map<char, string> m;
        set<string> str;
        if (pattern.length() != v.size())
            return false;
        for (int i = 0; i < pattern.length(); i++) {
            if (m.find(pattern[i]) != m.end()) {
                if (v[i] != m[pattern[i]])
                    return false;
            } else {
                if (str.find(v[i]) == str.end()) {
                    str.insert(v[i]);
                    m[pattern[i]] = v[i];
                } else
                    return false;
            }
        }
        return true;
    }
};