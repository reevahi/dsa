#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    bool isTerminalNode = false;
    TrieNode* nodes[26] = {nullptr};
};
void insertWord(TrieNode *root,string word,int index){
    if(index==word.size()){
        root->isTerminalNode = true;
        return;
    }
    TrieNode *curr = root->nodes[word[index]-'a'];
    if(curr == NULL){
        TrieNode *referenceNode = new TrieNode();
        root->nodes[word[index]-'a'] = referenceNode;
        curr = referenceNode;
    }
    insertWord(curr,word,index+1);
}

bool wordExist(TrieNode *root,string word,int index){
    if(index==word.size() && root->isTerminalNode){
        return true;
    }
    TrieNode *curr = root->nodes[word[index]-'a'];
    if(curr==NULL) return false;
    return wordExist(curr,word,index+1);
}

bool prefixExist(TrieNode *root,string word,int index){
    if(index==word.size()){
        return true;
    }
    TrieNode *curr = root->nodes[word[index]-'a'];
    if(curr==NULL) return false;
    return prefixExist(curr,word,index+1);
}
int main(){
    cout<<"Please enter 1 followed by the word to insert"<<endl;
    cout<<"Please enter 2 followed by the word you want to search"<<endl;
    cout<<"Please enter 3 followed by the word to check start with"<<endl;
    
    int input;
    cin>>input;
    TrieNode *head = new TrieNode();
    while(input){
        if(input==1){
            string s;
            cout<<"Enter the string"<<endl;
            cin>>s;
            insertWord(head,s,0);
            cout<<"Inserted"<<endl;
        }
        else if(input==2){
            string s;
            cout<<"Enter the string to search"<<endl;
            cin>>s;
            bool result = wordExist(head,s,0);
            (result==true) ? cout<<"Exists"<<endl : cout<<"Does not exist"<<endl;
        }
        else if(input ==3){
            string s;
            cout<<"Enter the prefix to search"<<endl;
            cin>>s;
            bool result = prefixExist(head,s,0);
            (result==true) ? cout<<"Exists"<<endl : cout<<"Does not exist"<<endl;
        }
        else break;
        cin>>input;
    }
}