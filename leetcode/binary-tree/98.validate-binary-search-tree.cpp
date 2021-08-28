// https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return soln_2(root);
    }
    
    // Recursive Approach DFS
    bool soln_1(TreeNode* root, TreeNode* max, TreeNode* min){
        if(!root) return true;
        
        if(max && root->val >= max->val || min && root->val <= min->val) return false;
        
        return soln_1(root->left, root, min) && soln_1(root->right, max, root);
    }
    
    // Iterative DFS
    bool soln_2(TreeNode* root){
        if(!root) return true;
        
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        
        while(root || !stk.empty()){
            if(root){
                stk.push(root);
                root = root->left;
            }else{
                auto top = stk.top();
                stk.pop();
                
                if(pre && pre->val >= top->val) return false;
                pre = top;
                root = top->right;
            }
        }
        return true;
    }
};