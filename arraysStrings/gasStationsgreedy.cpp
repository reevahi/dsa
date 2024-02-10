/*
@author github.com/iitzmahi
Here first we confirm that is there even a solution possible or
not, for that we just add up gas and cost array and if sumofgas >= sumofcost
then we can gauranteedly say that there is a solution and then we just keep on
traversing the arrays until we get a postive sum and then we just let that it
will be our answer if it is possible all the way
T.C. will be O(N) and S.C will be O(1)
link: https://leetcode.com/problems/gas-station/
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumofgas = 0;
        int sumofcost = 0;
        for (int i = 0; i < gas.size(); i++) {
            sumofgas += gas[i];
            sumofcost += cost[i];
        }
        int ans = 0;
        if (sumofgas < sumofcost)
            return -1;
        else {
            int gasRemaining = 0;
            for (int i = 0; i < gas.size(); i++) {
                gasRemaining += gas[i] - cost[i];
                if (gasRemaining < 0) {
                    gasRemaining = 0;
                    ans = i + 1;
                }
            }
        }
        return ans;
    }
};