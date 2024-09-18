#include<bits/stdc++.h>
using namespace std;
int knapsackTopDown(int value[],int weight[],int cap,int n,int t[][5]){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){
            if(weight[i-1]<=j){
                int with,without;
                with = value[i-1] + t[i-1][j-weight[i-1]];
                without = t[i-1][j];
                t[i][j] = max(with,without);
            }else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][cap];
}

int knapsackWithMemoization(int value[],int weight[],int cap,int n,int t[][5]){
    if(n==0 || cap ==0){
        t[n][cap]=0;
        return 0;
    }
    if(weight[n-1]<=cap){
        int temp1,temp2;
        if(t[n-1][cap-weight[n-1]]!=-1){
            temp1 = value[n-1] + t[n-1][cap-weight[n-1]];
        }else{
            temp1 = value[n-1]+knapsackWithMemoization(value,weight,cap-weight[n-1],n-1,t);
        }
        if(t[n-1][cap]!=-1){
            temp2 = t[n-1][cap];
        }else{
            temp2=knapsackWithMemoization(value,weight,cap,n-1,t);
        }
        t[n][cap] = max(temp1,temp2);
        return t[n][cap];
    }
    else{
        if(t[n-1][cap]!=-1)
        {
            t[n][cap]=t[n-1][cap];
            return t[n][cap];
        }else{
            t[n][cap] = knapsackWithMemoization(value,weight,cap,n-1,t);
            return t[n][cap];
        }
    }
}

int knapsack(int value[],int weight[],int cap,int n){
    if(n==0 || cap ==0) return 0;
    if(weight[n-1]<=cap){
        return max (
            (value[n-1]+knapsack(value,weight,cap-weight[n-1],n-1)),knapsack(value,weight,cap,n-1)
            );
    }
    else{
        return knapsack(value,weight,cap,n-1);
    }
}
int main(){
    int value[]={1,2,3};
    int weight[]={4,5,1};
    int cap=4;
    int n=3;
    int ans1 = knapsack(value,weight,cap,n);
    cout<<"Answer from recursive knapsack is "<<ans1<<endl;
    int t[4][5];
    memset(t,-1,sizeof(t));
    ans1 = knapsackWithMemoization(value,weight,cap,n,t);
    cout<<"Answer from recursive knapsack with memoization is "<<ans1<<endl;
    memset(t,0,sizeof(t));
    ans1 = knapsackTopDown(value,weight,cap,n,t);
    cout<<"Answer from Top Down knapsack is "<<ans1<<endl;
}