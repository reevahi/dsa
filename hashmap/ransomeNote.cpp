/*
@author github.com/iitzmahi
Just put all chars from ransomNote in a hashmap
and then just iterate over magazine string and at the end
just check that no char key in the hashmap should have
value >=0
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (int i = 0; i < ransomNote.length(); i++) {
            mp[ransomNote[i]]++;
        }
        for (int i = 0; i < magazine.length(); i++) {
            if (mp.find(magazine[i]) != mp.end()) {
                mp[magazine[i]]--;
            }
        }
        for (pair<char, int> mapPair : mp) {
            if (mapPair.second > 0)
                return false;
        }
        return true;
    }
};