#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<string,vector<pair<string,double>>> &mp,double &ans,double temp,unordered_set<string> &vis,string s,string d){
    if(s==d){
        ans=temp;
        return;
    }
    for(auto x : mp[s]){
        if(vis.find(x.first)==vis.end()){
            vis.insert(x.first);
            dfs(mp,ans,(temp*(x.second)),vis,x.first,d);
        }
    }
    return;
}
int main(){
    vector<vector<string>> equations = {
      {"a","b"},
      {"b","c"},
    };
    vector<vector<string>> queries = {
        {"a","c"},
        {"b","a"},
        {"a","e"},
        {"a","a"},
        {"x","x"}
    };
    vector<double> values = {
        2.0,3.0
    };
    unordered_map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<equations.size();i++){
            auto temp = equations[i];
            string a = temp[0];
            string b = temp[1];
            if(mp.find(a)==mp.end()){
                vector<pair<string,double>> temp1;
                temp1.push_back({b,values[i]});
                mp[a]=temp1;
            }
            else{
                mp[a].push_back({b,values[i]});
            }
            if(mp.find(b)==mp.end()){
                vector<pair<string,double>> temp1;
                temp1.push_back({a,(1/values[i])});
                mp[b]=temp1;
            }
            else{
                mp[b].push_back({a,(1/values[i])});
            }
        }
        
    for(auto entry : mp){
        cout<<"Adjacency for "<<entry.first<<endl;
        for(auto tempPair : entry.second){
            cout<<tempPair.first<<" "<<tempPair.second;
        }
        cout<<endl;
    }
    vector<double> result;
    for(int i=0;i<queries.size();i++){
        vector<string> curr_query = queries[i];
        string srcString = curr_query[0];
        string desString = curr_query[1];
        if(mp.find(srcString)==mp.end() || mp.find(desString)==mp.end()){
            result.push_back(-1.0);
            continue;
        }
        unordered_set<string> vis;
        double ans = -1.0;
        double temp = 1.0;
        vis.insert(srcString);
        dfs(mp,ans,temp,vis,srcString,desString);
        result.push_back(ans);
    }
    for(auto x : result){
        cout<<x<<" ";
    }
}