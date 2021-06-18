// saurabhraj042
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/260502/C%2B%2B-BFSDFS
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
        map<int,map<int,multiset<int>>> mp;
        trav(root,0,0,mp);
        for(auto x:mp){
            vector<int> col;
            for(auto y:x.second){
                col.insert(col.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }

    void trav(TreeNode* node,int x,int y,map<int,map<int,multiset<int>>> &mp){
        if(node){
            mp[x][y].insert(node->val);
            trav(node->left,x-1,y+1,mp);
            trav(node->right,x+1,y+1,mp);
        }
    }
};

