// https://leetcode.com/problems/shortest-common-supersequence/
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        // LCS variation
        int x = s1.length();
        int y = s2.length();
        
        vector<vector<int>> dp(x+1,vector<int>(y+1));
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }else{
                    if(s1[i-1] == s2[j-1]){
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        int i = x;
        int j = y;
        string s = "";
        
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                s += s1[i-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    s += s1[i-1];
                    i--;
                }else{
                    s += s2[j-1];
                    j--;
                }
            }
        }
        
        while(i > 0){
            s += s1[i-1];
            i--;
        }
        
        while(j > 0){
            s += s2[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
       
        return s;
    }
};