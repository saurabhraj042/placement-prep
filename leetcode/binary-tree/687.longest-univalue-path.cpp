// https://leetcode.com/problems/longest-univalue-path/
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int longestPath=0;
        go(root, longestPath);
        return longestPath;
    }
    
     int go(TreeNode* root, int& m){
        int l = root->left ? go(root->left, m) : 0;
        int r = root->right ? go(root->right, m) : 0;
        
        l = (root->left && root->left->val==root->val) ? l+1 : 0;
        r = (root->right && root->right->val==root->val) ? r+1 : 0;
        
        m=max(m,l+r);
        return max(l,r);
    }
};