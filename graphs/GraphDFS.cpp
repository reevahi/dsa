#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> *arr,int i,int *vis){
    if(!vis[i]){
        vis[i]=1;
        cout<<i<<" ";
        for(int j : arr[i]){
            if(!vis[j]){
                dfs(arr,j,vis);
            }
        }
    }
}
int main(){
    int num;
    cout<<"Enter the total number of Nodes"<<endl;
    cin>>num;
    vector<int> arr[num+1];
    for(int i=1;i<num+1;i++){
        cout<<"Enter the adjacents of "<<i<<endl;
        vector<int> temp;
        int temp1;
        cin>>temp1;
        while(temp1){
            temp.push_back(temp1);
            cin>>temp1;
        }
        arr[i]=temp;
    }
    for(int i=1;i<num+1;i++){
        cout<<"Adjacency for "<<i<<endl;
        for(int j : arr[i])
        cout<<" "<<j;
        cout<<endl;
    }
    int vis[num+1]={0};
    cout<<"The DFS of the graph is :"<<endl;
    dfs(arr,1,vis);
}