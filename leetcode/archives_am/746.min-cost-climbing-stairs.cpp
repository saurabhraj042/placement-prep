// https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        vector<int> dp(a.size() + 1, -1);
        int n = a.size();
        
        return min(solve(a, n - 1, dp), solve(a, n - 2, dp));
    }
    
    int solve(vector<int> &a, int idx,vector<int> &dp){
        if(idx < 0) return 0;
        
        if(idx == 0 || idx == 1) return a[idx];
        
        if(dp[idx] != -1) return dp[idx];
        
        dp[idx] = a[idx] + min(solve(a, idx - 1, dp), solve(a, idx - 2, dp));
        
        return dp[idx];
    }
};