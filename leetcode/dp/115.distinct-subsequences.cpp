// https://leetcode.com/problems/distinct-subsequences/
class Solution {
public:
    int numDistinct(string s, string t) {
        int x = s.length();
        int y = t.length();
        vector<vector<int>> dp(x+1,vector<int>(y+1));
        for(int i=0;i<=x;i++)
            for(int j=0;j<=y;j++)
                dp[i][j] = -1;
        
        return helper(s,x,t,y,dp);
    }
    
    int helper(string s,int x,string t,int y,vector<vector<int>> &dp){ 
        if(y == 0){
            return 1;
        }
        
        if(x == 0){
            return 0;
        }
        
        if(dp[x][y] != -1) return dp[x][y];
        
        if(s[x-1] == t[y-1]){
            dp[x][y] = helper(s,x-1,t,y,dp) + helper(s,x-1,t,y-1,dp);
        }else{
            dp[x][y] = helper(s,x-1,t,y,dp);
        }
        
        return dp[x][y];
    }
};