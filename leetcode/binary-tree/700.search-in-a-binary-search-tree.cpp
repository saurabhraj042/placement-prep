// https://leetcode.com/problems/search-in-a-binary-search-tree/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        
        if(root->val == val) return root;
        
        if(root->val > val){
            return searchBST(root->left, val);
        }
        
        return searchBST(root->right, val);
    }
};

