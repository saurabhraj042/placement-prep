/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        int temp = io(root, mx);
        return mx;
    }
    
    int io(TreeNode* root, int &mx){
        if(!root) return 0;
        
        int l = io(root->left, mx);
        int r = io(root->right, mx);
        if(l<0) l = 0;
        if(r<0) r = 0;
        
        mx = max({mx, root->val + max(l, r), l + r + root->val});
        
        return root->val + max(l, r);
    }
    
    
};