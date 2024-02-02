bool identicalTrees(TreeNode* p,TreeNode* q){
    //Here we will do preorder traversal for both the binary trees and check if they are same
    //Base case when they both will reach leaf node and check whether they are NULL
    //OtherWise we check for current node value and left and right subtree identical recursive call is
    //made.
    if(p==NULL || q==NULL) return p==q;
    return (p->val==q->val) && identicalTrees(p->left,q->left) && identicalTrees (p->right,q->right);
}