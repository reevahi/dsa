// equal sum partition -- Aditya Verma
#include<bits/stdc++.h>
using namespace std;
bool canBeDivided(vector<int> arr){
    int n = arr.size();
    int sum=0;
    for(auto x:arr){
        sum+=x;
    }
    if(sum%2==1) return false;
    int target = sum/2;
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0 && j!=0) dp[i][j]=false;
            if(j==0) dp[i][j]=true;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1]<=j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}
int main(){
    vector<int> arr = {1,3};
    cout<<canBeDivided(arr);
}