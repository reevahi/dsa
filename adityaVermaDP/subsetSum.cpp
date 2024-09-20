//Subset sum problem
#include<bits/stdc++.h>
using namespace std;
bool isSubsetPresent(int arr[],int target,int n){
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0 && j!=0) dp[i][j]=false;
            if(j==0) dp[i][j]=true;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}
int main(){
    int arr[]={2,1,9,6,8,11,7};
    int target=8;
    int n=7;
    bool ans = isSubsetPresent( arr, target, n);
    ans ? cout<<"Subset Present" : cout<<"subset not present";
}