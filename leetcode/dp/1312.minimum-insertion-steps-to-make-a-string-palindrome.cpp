// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
class Solution {
public:
    int minInsertions(string A) {
        // LPS variation
        string B = A;
        reverse(B.begin(),B.end());
        int n = A.length();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }else{
                    if(A[i-1] == B[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        return n - dp[n][n];
    }
};