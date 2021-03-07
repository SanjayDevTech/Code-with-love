// Implemented for solving leetcode problem #700

typedef struct TreeNode{
		int val;
     	struct TreeNode *left;
     	struct TreeNode *right;
}node;

node* searchBST(struct node* root, int val){
    if(!root)
        return root;

    if(root->val==val)
        return root;
    
    if(root->val>val)
       return searchBST(root->left,val);
    else
       return searchBST(root->right,val);
    return root;
}