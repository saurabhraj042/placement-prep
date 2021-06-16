// saurabhraj042
// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    void solve(vector<int> &a,TreeNode* n){
        if(n==NULL) return;

        solve(a,n->left);
        a.push_back(n->val);
        solve(a,n->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(ans,root);
        return ans;
    }
};

