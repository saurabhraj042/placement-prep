class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        
        for(int i=1;i<dp.size();i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = min(dp[i],dp[i - j*j] + 1);
            }
        }
        
        return dp[n];
    }
    
    // https://www.youtube.com/watch?v=aZuQXkO0-XA
};