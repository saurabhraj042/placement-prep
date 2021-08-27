// saurabhraj042
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        // map[col][row] = set of nodes in the resp column
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int row = p.second.second;
            int col = p.second.first;
            
            mp[col][row].insert(node->val);
            
            if(node->left) q.push({node->left, {col-1, row+1}});
            if(node->right) q.push({node->right, {col+1, row+1}});
        }
        
        for(auto x:mp){
            vector<int> columns;
            for(auto z:x.second){
                columns.insert(columns.end(),z.second.begin(),z.second.end());
            }
            ans.push_back(columns);
        }
        
        return ans;
    }
};