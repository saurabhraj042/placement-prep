// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        // LCS variation
        int x = a.size();
        int y = b.size();
        
        vector<vector<int>> dp(x+1,vector<int>(y+1));
        int ans = 0;
        
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }else{
                    if(a[i-1] == b[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                        ans = max(ans,dp[i][j]);
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        
    
        return ans;
    }
};