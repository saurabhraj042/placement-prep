// https://leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Recursive Backtracking approach
        
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans,0,temp,nums);
        return ans;
    }
    
    void helper(vector<vector<int>> &ans,int idx,vector<int> &temp,vector<int> &nums){
        ans.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            helper(ans,i+1,temp,nums);
            temp.pop_back();
        }
    }
};