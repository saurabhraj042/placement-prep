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
        
        // 2D mapping of the tree with x and y coordinates
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int verLevel = p.second.second;
            int horLevel = p.second.first;
            
            mp[horLevel][verLevel].insert(node->val);
            
            if(node->left) q.push({node->left,{horLevel-1,verLevel+1}});
            if(node->right) q.push({node->right,{horLevel+1,verLevel+1}});
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