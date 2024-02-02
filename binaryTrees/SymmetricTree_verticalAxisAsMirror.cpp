bool symmetricTree(TreeNode* root){
    if(root==NULL) return true;
    return 
}

bool symmetricTreeHelper(TreeNode* p, TreeNode* q){
    if(p==NULL || q==NULL) return p==q;
    return (p->val == q->val) && symmetricTreeHelper(p->left,q->right) && symmetricTreeHelper(p->right,q->left);
}

//Here we check whehter the left and right part are mirror image of each other
//will make a helper func and then we will check whether for two nodes that its left is equal to its right and
//vice versa before which we evaluate the value of both the nodes
//base func will be when both the nodes are null then we simple return