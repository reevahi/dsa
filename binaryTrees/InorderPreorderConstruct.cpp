unordered_map<int,int> mp;
TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder){
    mp.clear();
    for(int i =0; i<inorder.size()-1;i++){
        mp[inorder[i]]=i;
    }

    return buildTreeHelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}

TreeNode* buildTreeHelper(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd){
    if(preStart > preEnd || inStart > inEnd) return NULL;
    auto root = new TreeNode(preorder[preStart]);
    int inRoot = mp[root->val];
    int leftNumbers = inRoot - inStart;
    root->left = buildTreeHelper(preorder,preStart + 1,preStart + leftNumbers,inorder,inStart,inRoot -1);
    root->right = buildTreeHelper(preorder,preStart+leftNumbers + 1 , preEnd,inorder, inRoot + 1 , inEnd);
}