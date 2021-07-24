class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
        vector<vector<int>> dp(x.length()+1,vector<int>(y.length()+1));
        
        for(int i=1;i<=x.length();i++){
            for(int j=1;j<=y.length();j++){
                
                if(x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1] +1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[x.length()][y.length()];
    }
};