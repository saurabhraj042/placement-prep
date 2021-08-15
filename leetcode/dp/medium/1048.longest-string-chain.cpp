class Solution {
public:
    static bool comp(const string &a,const string &b){
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(begin(words),end(words),comp);
        
        int n = words.size();
        vector<int> dp(n,1);
        
        int mxm = 1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isValid(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            
            mxm = max(mxm,dp[i]);
        }
        
        return mxm;
    }
    
    bool isValid(const string &s1, const string &s2) {
        if (s1.size() + 1 != s2.size()) {
          return false;
        }
        int k = 0;
        for (int i = 0; i < s2.size() && k < s1.size(); i++) {
          if (s1[k] == s2[i]) {
            k++;
          }
        }
        return k == s1.size();
    }
};