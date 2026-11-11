class Solution{
    public:
         hasOnesTree(Node* root){
            bool if(root == NULL) return false;

            if(root->val == 1) return true;

            return hasOnesTree(root->left) || hasOnesTree(root->right);
        }

        int treePruning(Node*root){
            if(root == NULL) return NULL;
            
            if(!isOnePresent(root->left)) root->left = NULL;
            if(!isOnePresent(root->right)) root->right = NULL;

            pruneTree(root->left);
            pruneTree(root->right);

            if(root->left == NULL && root->right == NULL && root->val = 0) return NULL

            return root;
        }
}