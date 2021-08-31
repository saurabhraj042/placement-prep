// https://leetcode.com/problems/range-sum-of-bst/
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        preOrder(root, sum, low, high);
        return sum;
    }
    
    void preOrder(TreeNode* root, int &sum, int lo, int hi){
        if(!root) return;
        
        if(lo <= root->val && root->val <= hi){
            sum += root->val;
            preOrder(root->left, sum, lo, hi);
            preOrder(root->right, sum, lo, hi);
        }else if(root->val > hi){
            preOrder(root->left, sum, lo, hi);
        }else if(root->val < lo){
            preOrder(root->right, sum, lo, hi);
        }
    }
};