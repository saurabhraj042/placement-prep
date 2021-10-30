// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        soln_1(root, ans);
        return ans;
    }
    
    void soln_1(Node* root, vector<int> &ans){
        if(!root) return;
        
        ans.push_back(root->val);
        
        for(auto c : root->children){
            soln_1(c, ans);
        }
    }
};