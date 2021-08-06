// https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        // Recur + memoization
        int len = nums.size();
        vector<int> dp(len+1,-1);
        
        int maxProfit = solve(nums,len,dp);
        return maxProfit;
    }
    
    int solve(vector<int>& nums,int n,vector<int> &dp){
        if(n == 1) return dp[n] = nums[n-1];
        
        if(n == 2) return dp[n] = max(nums[n-1],nums[n-2]);
        
        if(dp[n] != -1) return dp[n];
        
        int inc = nums[n-1] + solve(nums,n-2,dp);
        int exc = solve(nums,n-1,dp);
        
        return dp[n] = max(inc,exc);
    }
};