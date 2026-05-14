int sumLeaves(TreeNode* root){
    if(!root) return 0;  // base case
    if(!root->left && !root->right) reutn root->val; // if leaf, return its value
    return sumLeaves(root->left) + sumLeaves(root->right); // else recurse left + right
}