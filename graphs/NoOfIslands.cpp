#include<bits/stdc++.h>
using namespace std;
void bfs (vector<vector<int>>& grid, vector<vector<int>>& vis,int i,int j){
    queue<pair<int,int>> q;
    vector<int> rowDel = {0,-1,0,1};
    vector<int> colDel = {-1,0,1,0};
    int row = grid.size();
    int col = grid[0].size();
    q.push({i,j});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        vis[r][c]=1;
        q.pop();
        for(int x = 0;x<4;x++){
            if((r+rowDel[x])>=0 && (r+rowDel[x]) <row && (c+colDel[x])>=0 && (c+colDel[x]) < col){
                if(vis[r+rowDel[x]][c+colDel[x]]==0){
                    q.push({r+rowDel[x],c+colDel[x]});
                    //vis[r+rowDel[x]][c+colDel[x]]=1;
                }
            }
        }
    }
}
int main(){
    vector<vector<int>> grid = {
        {1,1,1,1,0},
        {1,1,0,1,0},
        {1,1,0,0,0},
        {0,0,0,0,0}
    };
    
    vector<vector<int>> vis(4,vector<int>(5,0));
    int row = grid.size();
    int col = grid[0].size();
    int count =0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1 && vis[i][j]==0){
                bfs(grid,vis,i,j);
                count++;
            }
        }
    }
    cout<<"Number of islands are "<<count<<"\n";
}