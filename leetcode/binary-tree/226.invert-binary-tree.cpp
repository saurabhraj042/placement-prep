// saurabhraj042
// https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        auto link = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(link);
        return root;
    }
};

