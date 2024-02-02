void helperFunc(TreeNode* root){
    if(root==NULL) return;
    auto leftSubTree = root->left;
    root->left = root->right;
    root->right = leftSubTree;
    helperFunc(root->left);
    helperFunc(root->right);
}
TreeNode* mirrorImage(TreeNode* root){
    helperFunc(root);
    return root;
}

//we will swap left subtree with right subtree for a given node traversed recusively in preorder traversal
//Base case will be that the node is NULL so we will simply return void