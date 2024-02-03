unordered_map<int,int> mp;
TreeNode * buildTree(vector<int>& postorder, vector<int>& inorder){
    for(int i = 0; i<inorder.size();i++){
        mp[inorder[i]] = i;
    }

    return buildTreeHelper(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
}

TreeNode* buildTreeHelper(vector<int>& postorder, int ps, int pe, vector<int>& inorder ,int is,int ie){
    if(ps > pe || is > ie) return NULL;
    auto root = new TreeNode(postorder[pe]);
    int inRoot = mp[root->val];
    int leftNumbers = inRoot - is;
    root->left = buildTreeHelper(postorder,ps,ps + leftNumbers -1 ,inorder,is,inRoot -1);
    root->right = buildTreeHelper(postorder,ps + leftNumbers ,pe -1 ,inorder,inRoot+1,ie)
}