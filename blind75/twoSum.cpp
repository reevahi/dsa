#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(arr,target);
    cout<<ans[0]<<ans[1];
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        mp[target-x]=i;
    }
    for(int i =0;i<nums.size();i++){
        if(mp.find(nums[i])!=mp.end()){
            return {i,mp[nums[i]]};
        }
    }
    return {0,0};
}