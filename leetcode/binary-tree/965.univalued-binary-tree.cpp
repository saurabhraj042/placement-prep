// https://leetcode.com/problems/univalued-binary-tree/
// Time Complexity : O(Nodes);
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        int uni_val = root->val;
        bool validity = isValid(root, uni_val);
        return validity;
    }
    
    bool isValid(TreeNode* root, int uni_val){
        if(!root) return true;
        
        if(root->val != uni_val) return false;
        
        bool left_check = isValid(root->left, uni_val);
        bool right_check = isValid(root->right, uni_val);
        
        return left_check && right_check;
    }
};