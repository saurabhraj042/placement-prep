// https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // LCS variation
        int x = s.length();
        int y = t.length();
        
        vector<vector<int>> dp(x+1,vector<int>(y+1));
        
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }else{
                    if(s[i-1] == t[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        return dp[x][y] == x;
    }
};