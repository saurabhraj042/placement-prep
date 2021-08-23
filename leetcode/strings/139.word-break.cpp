class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> a;
        for(auto x:wordDict) a.insert(x);
        vector<int> dp(size(s),-1);
        
        return soln_1(0,s,a,dp);
    }
    
    bool soln_1(int start,string s,unordered_set<string> &a,vector<int> &dp){
        int n = size(s);
        
        if(start == n) return 1;
        string temp;
        
        if(dp[start] != -1) return dp[start];
        
        for(int i=start;i<n;i++){
            if(a.find(temp+=s[i]) != a.end() && soln_1(i+1,s,a,dp)){
                return dp[start] = 1;
            }
        }
        
        return dp[start] = 0;
    }
};