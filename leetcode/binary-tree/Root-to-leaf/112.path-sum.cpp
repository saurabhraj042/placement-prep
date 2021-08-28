// saurabhraj042
// https://leetcode.com/problems/path-sum/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        if(!root->left && !root->right){
            return root->val==targetSum;
        }

        targetSum -= root->val;

        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
    }
};

