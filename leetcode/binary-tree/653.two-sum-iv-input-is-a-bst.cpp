/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 */

// @lc code=start
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
class Solution {
public:
    bool search(TreeNode* root,TreeNode* cur,int val){
        if(root==NULL) return false;

        return (root->val==val) && (root!=cur)
            || (root->val < val) && search(root->right,cur,val)
            || (root->val > val) && search(root->left,cur,val);
    }
    bool dfs(TreeNode* root,TreeNode* cur,int k){
        if(cur==NULL) return false;

        return search(root,cur,k - cur->val) || dfs(root,cur->left,k) || dfs(root,cur->right,k);
    
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root,root,k);
    }
};

