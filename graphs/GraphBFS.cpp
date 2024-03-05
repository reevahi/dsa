#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> arr[],int vis[]){
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int x : arr[curr]){
            if(!vis[x]){
                q.push(x);
            vis[x]=1;
            }
        }
    }
}
int main(){
    int nums;
    cout<<"Enter the number of nodes"<<endl;
    cin>>nums;
    vector<int> arr[nums+1];
    for(int i=1;i<nums+1;i++){
        cout<<"Enter the adjacency of "<<i<<endl;
        vector<int> temp;
        int temp1;
        cin>>temp1;
        while(temp1){
            temp.push_back(temp1);
            cin>>temp1;
        }
        arr[i]=temp;
    }
    for(int i=1;i<nums+1;i++){
        cout<<"Adjacency of "<<i<<endl;
        for(int j:arr[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    int vis[nums+1]={0};
    bfs(arr,vis);
}