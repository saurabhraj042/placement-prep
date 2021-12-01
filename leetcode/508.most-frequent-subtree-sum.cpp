// https://leetcode.com/problems/most-frequent-subtree-sum/
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int> ans;
        inOrder(root, mp);
        
        int mx_fq = INT_MIN;
        for(auto x : mp) mx_fq = max(mx_fq, x.second);
        
        for(auto x : mp){
            if(x.second == mx_fq){
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
    
    void inOrder(TreeNode* root, unordered_map<int, int> &mp){
        if(!root) return;
        
        inOrder(root->left, mp);
        
        int sum = 0;
        findSum(root, sum);
        mp[sum]++;
        
        inOrder(root->right, mp);
    }
    
    void findSum(TreeNode* root, int &sum){
        if(!root) return;
        
        sum += root->val;
        
        findSum(root->left, sum);
        findSum(root->right, sum);
    }
};