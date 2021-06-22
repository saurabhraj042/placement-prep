// saurabhraj042
//https://leetcode.com/problems/cousins-in-binary-tree/

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            bool isX = false;
            bool isY = false;

            int n = q.size();

            while (n--)
            {
                auto p = q.front();
                q.pop();
                
                if(p->val==x) isX = true;
                if(p->val==y) isY = true;

                if(p->left && p->right){
                    if(p->left->val==x && p->right->val==y){
                        return false;
                    }
                    if(p->left->val==y && p->right->val==x){
                        return false;
                    }
                }

                if(p->left){
                    q.push(p->left);
                }

                if(p->right) q.push(p->right);

            }
            


            if(isX && isY) return true;
        }

        return false;
    }
};

