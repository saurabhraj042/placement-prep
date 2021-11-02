// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        soln_1(root, ans);
        return ans;
    }
    
    void soln_1(Node* root, vector<int> &ans){
        if(!root) return;
        
        for(auto c : root->children){
            soln_1(c, ans);
        }
        
        ans.push_back(root->val);
    }
};