TreeNode* pruneTree(TreeNode* root) {
    
    if(!root) return root;
    
    root->left = pruneTree(root->left);       //postorder traversal
    root->right = pruneTree(root->right);
    
    if(root->val == 0 && !root->left && !root->right){    //if root->val is 0, then check if it's 
        return NULL;                                      //leftSubtree and rightSubtree exists or not
    }                                                     //if not return NULL
    return root;
}
