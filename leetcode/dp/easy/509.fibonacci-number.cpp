// https://leetcode.com/problems/fibonacci-number/
class Solution {
public:
    int fib(int n) {
        // Optimal DP soluchan ^_^
        
        int dp[31] = {0};
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i= 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};