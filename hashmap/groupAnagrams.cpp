/*
@author github.com/iitzmahi
Here we just have to maintain a map that holds a key as string
and then we just run a loop, and check that the sorted version of
that string is present as a key in the map or not
-->(optimal approach) we have to just run a forloop and make a frequncy array
for that string and convert the frequency array to string and check whether it
is present in the map or not
*/
class Solution {
public:

    string frequencyarraystring(string s){
        vector<int> arr(26,0);
        for(int i=0;i<s.length();i++){
            arr[s.at(i) - 'a']++;
        }
        string temp = "";
        for(int i=0;i<26;i++){
            temp=temp+to_string(arr[i])+ '#';
        }
        return temp;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //T.C. --> O(NlogN)
        // unordered_map<string, vector<string>> mp;
        // for (int i = 0; i < strs.size(); i++) {
        //     string s = strs[i];
        //     sort(s.begin(), s.end());
        //     if (mp.find(s) != mp.end()) {
        //         mp[s].push_back(strs[i]);
        //     } else {
        //         vector<string> temp;
        //         temp.push_back(strs[i]);
        //         mp[s] = temp;
        //     }
        // }
        // vector<vector<string>> ans;
        // for (auto entry : mp) {
        //     ans.push_back(entry.second);
        // }
        // return ans;

        //T.C. --> O(N)

        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string temp = frequencyarraystring(strs[i]);
            if(mp.find(temp)!=mp.end()){
                mp[temp].push_back(strs[i]);
            }
            else{
                vector<string> v;
                v.push_back(strs[i]);
                mp[temp]=v;
            }
        }
        for( auto entry : mp){
            ans.push_back(entry.second);
        }
        return ans;
    }
};