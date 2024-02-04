class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        for(int i = 1 ; i <=numRows; i++){
            vector<int> temp;
            int ans = 1;
            temp.push_back(ans);
            for(int j = 1; j<i; j++){
                ans *=(i-j);
                ans /=(j);
                temp.push_back(ans);
            }
            pascalTriangle.push_back(temp);
        }
        return pascalTriangle;
    }
};