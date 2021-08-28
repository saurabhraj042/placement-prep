// https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int levels = height(root) - 1;
        vector<vector<int>> ans;
        map<int, vector<int>> mp;
        soln_1(root, levels, 0, mp);
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
    
    void soln_1(TreeNode* root, int l, int cur_l, map<int, vector<int>> &mp){
        if(cur_l > l || !root) return;
        
        mp[cur_l].push_back(root->val);
        
        soln_1(root->left, l, cur_l + 1, mp);
        soln_1(root->right, l, cur_l + 1, mp);
    }
};