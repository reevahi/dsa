/*
This question can be of two types
I. If the given array is sorted
II. If the given array is not sorted

For the first type we have to just apply two pointers approach and return the indexes having the target
sum
For the second type the most optimal approach is to take a map and put target-numbers[i], i in the map
and then traverse the array again and check whether it is present in the map;
link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j] == target){
                return {++i,++j};
            }
            else if(numbers[i] + numbers[j] >target) j--;
            else i++;
        }
        return {};
    }
};


//-------------------------------------------------------------------------------------//

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i=0;i<numbers.size();i++){
            mp[target-numbers[i]]=i;
        }
        for(int i=0;i<numbers.size();i++){
            if(mp.find(numbers[i])!=mp.end()){
                int index1 = i;
                int index2 = mp[numbers[i]];
                if(index2<index1){
                    swap(index1,index2);
                }
                result.push_back(++index1);
                result.push_back(++index2);
                return result;
            }
        }
        return result;
    }
};

