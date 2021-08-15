// https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 2) return n ? nums[0] : 0;
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return max(solve(nums,0,n-2,dp),solve(nums,1,n-1,dp));
    }
    
    int solve(vector<int> &a,int start,int end,vector<vector<int>> &dp){
        if(end<start) return 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int exc = solve(a,start,end-1,dp); 
        int inc = a[end] + solve(a,start,end-2,dp);
        
        return dp[start][end] = max(exc,inc);
    }
    
    /*
        # state : dp[i] = max(a[i-1] + dp[i-2],dp[i-1])
    */
};