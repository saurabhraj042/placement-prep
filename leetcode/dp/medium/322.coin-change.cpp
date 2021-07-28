// https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& arr, int x) {
        int n = arr.size();
        int mx = INT_MAX - 1;
        vector<vector<int>> dp(n+1,vector<int>(x+1));
        
        for(int j=0;j<=x;j++) dp[0][j] = mx;
        for(int i=1;i<=n;i++) dp[i][0] = 0;
        for(int j=1;j<=x;j++) dp[1][j] = (j%arr[0]==0) ? j/arr[0] : mx;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=x;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = min(1 + dp[i][j - arr[i-1]],dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n][x] >= mx) return -1;
        return dp[n][x];
    }
};