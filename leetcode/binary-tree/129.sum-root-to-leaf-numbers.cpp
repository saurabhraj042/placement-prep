// saurabhraj042
//https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    int ans=0;
    void dfs(TreeNode* n,int s){
        if(!n) return;

        s = s*10 + n->val;

        if(!n->left && !n->right){
            ans += s;
            return;
        }

        dfs(n->left,s);
        dfs(n->right,s);
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root,0);
        return ans;
    }
};

