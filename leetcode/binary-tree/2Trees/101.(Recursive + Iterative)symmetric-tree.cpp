
class Solution {
public:
/*
    Think of the solution where you have to compare
    two Binary Trees
*/
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

    // Recursive approach
    int isSymmetric(TreeNode* A) {
        return !A || rec(A->left,A->right);
    }

    int rec(TreeNode* l, TreeNode* r){
        if(!l || !r) return 0;

        if(l->val != r->val) return 0;

        return rec(l->left, r->right) && rec(l->right, r->left);
    }
};

