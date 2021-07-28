// https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Top Down DP
        int sum = 0;
        int n = nums.size();
        
        for(auto x:nums) sum += x;
        
        if(sum%2) return false;
        sum /= 2;
        
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                
                if(i==0 && j!=0){
                    dp[i][j] = false;    
                }else if(j==0){
                    dp[i][j] = true;
                }else{
                    if(nums[i-1] <= j){
                        dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        
       return dp[n][sum];
    }
    
   
};