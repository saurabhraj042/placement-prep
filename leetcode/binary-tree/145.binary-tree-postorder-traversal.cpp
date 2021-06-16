// saurabhraj042
// https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(ans,root);
        return ans;
    }
    void solve(vector<int> &a,TreeNode* n){
        if( n==NULL ) return;

        solve(a,n->left);
        solve(a,n->right);
        a.push_back(n->val);
    }
};

