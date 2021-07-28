// https://leetcode.com/problems/coin-change-2/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0 && j!=0){
                    dp[i][j] = 0;
                }else if(j==0){
                    dp[i][j] = 1;
                }else{
                    if(coins[i-1] <= j){
                        dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        
        return dp[n][amount];
    }
};