// https://leetcode.com/problems/subtree-of-another-tree/
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(!root) return false;
        
        if(isSame(root, subRoot)) return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool isSame(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        
        if(!a || !b) return false;
        
        if(a->val != b->val) return false;
        
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
};