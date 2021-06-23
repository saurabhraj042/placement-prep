// saurabhraj042
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
class Solution {
public:
    TreeNode* build(vector<int> &a,int s,int e){
        if(s>e) return NULL;
        
        int mid = s + (e-s)/2;
        
        TreeNode* root = new TreeNode(a[mid]);
        root->left = build(a,s,mid-1);
        root->right = build(a,mid+1,e);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};