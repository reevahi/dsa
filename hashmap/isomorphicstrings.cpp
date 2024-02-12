/*
@author github.com/iitzmahi
Here we just have to iterate over the 2 string and chech for the current
character in the string s is already mapped to a character of t 2 cases:
--> If you find the current character of string s is already mapped --> here you
just have to check that the char that it is mapped to is same as the current
char in t string
--> If the current char of string s is not present in the map, then you just
have to cehck that the current char in string t is not mapped to any other
string
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> m;
        set<char> s1;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end()) {
                if (m[s[i]] != t[i])
                    return false;
            } else {
                if (s1.find(t[i]) == s1.end()) {
                    m[s[i]] = t[i];
                    s1.insert(t[i]);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};