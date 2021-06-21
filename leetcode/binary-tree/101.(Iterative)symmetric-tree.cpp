/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> sl, sr;
        sl.push(root);
        sr.push(root);
        TreeNode * lp = root->left, *rp = root->right;
        
        while(lp || ! sl.empty() || rp || !sl.empty()){
            if((!lp && rp) || (lp && !rp)) return false;
            
            if(lp && rp){
                if(lp->val != rp->val) return false;
                sl.push(lp);
                sr.push(rp);
                lp = lp->left;
                rp = rp->right;
            }else{
                lp = sl.top()->right;
                rp = sr.top()->left;
                sl.pop();
                sr.pop();
            }
        }
        return true;
        
    }
};

