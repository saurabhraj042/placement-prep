// https://leetcode.com/problems/perfect-squares/
class Solution {
public:
    int numSquares(int n) {
        vector<int> sqs;
        
        // O(sqrt(N));
        for(int i=1;i*i<=n;i++){
            int no = i*i;
            sqs.push_back(no);
        }
        
        int len = sqs.size();
        
        vector<vector<int>> dp(len+1,vector<int>(n+1,-1));
        
        return solve(sqs,n,len,dp);
    }
    
    int solve(vector<int> &sq,int target_sum,int n,vector<vector<int>> &dp){
        if(n==0){
            if(target_sum==0){
                return 0;
            }
            return -1;
        }
        
        if(dp[n][target_sum] != -1) return dp[n][target_sum];
        
        int inc=-1,exc=-1;
        exc = solve(sq,target_sum,n-1,dp);
        
        if(sq[n-1] <= target_sum){
            inc = solve(sq,target_sum-sq[n-1],n,dp);
        }
        
        int temp;
        
        if(inc==-1 && exc==-1) return dp[n][target_sum] = -1;
        if(exc==-1) return dp[n][target_sum] = inc+1;
        if(inc==-1) return dp[n][target_sum] = exc;
        
        return dp[n][target_sum] = min(inc+1,exc);
    }
    
    /*
        # let's say that I'll build an array of perfect square numbers
        that lies bw '1' to 'n'
        
        # Now I'll find a sequence with minm no of integers from that array
        whose sum is 'n' and I'm allowed to repeat integers as many times as 
        I want
        
        # As a conclusion this ques is just a variation of unbounded KnapSack
    */
};