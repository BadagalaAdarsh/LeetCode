class Solution{
public:
  int pseudoPalindromicPaths(TreeNode *root, int count = 0){
    // dfs way to find the number of pseudo palindromic paths
    if (!root)
      return 0;
    count ^= 1 << root->val;
    int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
    if (!root->left && !root->right && (count & (count - 1)) == 0)
      res++;
    return res;
  }
