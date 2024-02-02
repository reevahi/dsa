int maxDepth(TreeNode* root){
    // Here we will traverse every node and then for that node we will calculate maxHight of its left subtree
    //and right subtree and then we will return 1 + maximum hight from left and right subtree
    if(root==NULL) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh,rh);
}