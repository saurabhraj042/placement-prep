// https://leetcode.com/problems/deepest-leaves-sum/
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0, i;
        
        while(size(q)){
            for(i = size(q) - 1, res = 0; i >= 0; i--){
                auto node = q.front();
                q.pop();
                
                res += node->val;
                
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        
        return res;
    }
 
};