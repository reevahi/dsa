#include<bits/stdc++.h>
using namespace std;
int main(){
    /*
    1-----2
    1-----3
    3-----4
    3-----5
    4-----5
    2-----4
    */
    vector<int> adjArr[6];
    for(int i = 1;i<6;i++){
        int input=1;
        cout<<"Please enter all neighbours of "<<i<<"\n";
        vector<int> temp;
        cin>>input;
        while(input){
            temp.push_back(input);
            cin>>input;
        }
        adjArr[i]=temp;
    }
    for(int i=1;i<6;i++){
        cout<<"Adjacency list for "<<i<<"\n";
        for(int j : adjArr[i]){
            cout<<" "<<j<<" ";
        }
        cout<<"\n";
    }
}