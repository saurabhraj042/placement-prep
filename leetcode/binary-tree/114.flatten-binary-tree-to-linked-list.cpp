// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
class Solution {
public:
    TreeNode* rightSubtree = nullptr;
    void flatten(TreeNode* root) {
        if(!root) return;

        // finding the right subtree for correct order
        flatten(root->right);
        
        // going deep into the left Subtree to find the rightmost tail node
        flatten(root->left);

        // changing the links of nodes
        root->right = rightSubtree;
        root->left = nullptr;
        rightSubtree = root;
    }
};

