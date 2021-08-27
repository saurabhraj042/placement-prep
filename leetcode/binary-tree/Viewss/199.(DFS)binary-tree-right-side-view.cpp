// saurabhraj042
// https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
        // DFS Approach
        vector<int> ans;
        if(root==NULL) return ans;
        solve(ans,root,0);
        return ans;
    }
    
    void solve(vector<int> &a,TreeNode* n,int l){
        if(n == NULL) return;
        
        //Imp Observation that (size-1)th index is rep the level itself
        if(l == a.size()) a.push_back(n->val);
        
        solve(a,n->right,l+1);
        solve(a,n->left,l+1);
    }
};