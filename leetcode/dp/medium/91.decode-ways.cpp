class Solution {
public:
    int numDecodings(string s) {
        // Simple Recur + Memo
        int len = s.length();
        
        vector<int> dp(len+1,-1);
        dp[len] = 1;
        
        if(s.empty()) return 0;
        
        return solve(0,s,dp);
    }
    
    int solve(int idx,string &s,vector<int> &dp){
        size_t n = s.length();
                
        if(s[idx] == '0') return dp[idx] = 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int ways = solve(idx+1,s,dp);
        
        if(idx < n-1 && (s[idx]=='1' || s[idx]=='2' && s[idx+1]<='6')){
            ways += solve(idx+2,s,dp);
        }
        
        return dp[idx] = ways;
    }
};