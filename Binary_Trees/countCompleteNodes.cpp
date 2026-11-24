// count complete nodes with TC < 0(n)
// 1.will understand the code and problems
// 2.will do pre-requisite problems for this problem
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftHeight = 0;
        TreeNode* leftNode = root;
        while (leftNode != nullptr) {
            leftHeight++;
            leftNode = leftNode->left;
        }
        
        int rightHeight = 0;
        TreeNode* rightNode = root;
        while (rightNode != nullptr) {
            rightHeight++;
            rightNode = rightNode->right;
        }
        
        // Perfect binary tree shortcut: avoids visiting all nodes
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1; 
        }
        
        // Only recurse if the tree is not perfect
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
