// https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // LCS variation
        int len = nums.size();
        set<int> temp;
        vector<int> targ;
        
        for(auto x:nums) temp.insert(x);
        for(auto x:temp) targ.push_back(x);
        
        int len2 = targ.size();
        vector<vector<int>> dp(len+1,vector<int>(len+1));
        
        for(int i=0;i<=len;i++){
            for(int j=0;j<=len2;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }else{
                    if(nums[i-1] == targ[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        return dp[len][len2];
    }
};