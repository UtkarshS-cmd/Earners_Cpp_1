class Solution {
public:
    int minDepth(TreeNode* root) {
        // 1. Handle an empty tree
        if (root == nullptr) {
            return 0;
        }
        
        // 2. A leaf node has a depth of 1
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        // 3. If one child is null, only explore the non-null child
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }
        
        // 4. If both children exist, take the minimum of the two paths
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
