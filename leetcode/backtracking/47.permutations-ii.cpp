// https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        dfs(nums,temp,ans,used);
        return ans;
    }
    void dfs(vector<int>& nums,vector<int>& temp,vector<vector<int>> &ans,vector<bool> used){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(used[i] || i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            
            temp.push_back(nums[i]);
            used[i] = 1;
            dfs(nums,temp,ans,used);
            used[i] = 0;
            temp.pop_back();
        }
    }
};