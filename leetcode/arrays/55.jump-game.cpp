// https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return soln_1(nums);
    }
    
    // DP approach : O(N)
    bool soln_1(vector<int> &a){
        size_t n = size(a);
        if(n==1) return true;
        // dp[i] : The farthest index we can reach given allowed steps from 0 to i
        int dp[n];
        dp[0] = a[0];
        
        for(int i=1;i<n-1;i++){
            // Since the last ind is not capable to reach the current ind 'i'
            if(dp[i-1] < i) return false;
            
            // It's either the dp[i - 1] or i + nums[i] whichever one is larger
            dp[i] = max(dp[i-1],i + a[i]);
            
            // dp[i] >= last index, that means it can already reach the end of the array given the steps allowed from 0 to i
            
            if(dp[i] >= n-1) return true;
        }
        
        if(dp[n-2] >= n-1) return true;
        
        return false;
    }
};