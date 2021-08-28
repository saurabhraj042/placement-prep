
// https://leetcode.com/problems/path-sum-ii/
class Solution {
public:
    void paths(TreeNode* n,int sum,vector<int> t,vector<vector<int>> &ans){
        if(!n) return;
        
        t.push_back(n->val);
        
        if(!n->left && !n->right) {
            if(n->val==sum){
                ans.push_back(t);
            }
            return;
        }
        
        paths(n->left,sum-n->val,t,ans);
        paths(n->right,sum-n->val,t,ans);
    }
    vector<vector<int>> pathSum(TreeNode* A, int B) {
        vector<int> t;
        vector<vector<int>> ans;
        paths(A,B,t,ans);
        return ans;
    }
};

