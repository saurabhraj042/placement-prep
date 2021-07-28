// https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Recursion + Memoization Approach
        int sum = 0;
        int n = nums.size();
        
        for(auto x:nums) sum += x;
        
        if(sum%2) return false;
        
        vector<vector<int>> table(n+1,vector<int>(sum+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                table[i][j] = -1;
            }
        }
        
        sum /= 2;
        return solve(nums,sum,n,table);
    }
    
    bool solve(vector<int> & arr,int sum,int n,vector<vector<int>> &table){
        if(sum==0) return true;
        if(n==0 && sum!=0) return false;
        
        if(table[n][sum] != -1) return table[n][sum];
        
        bool exc = solve(arr,sum,n-1,table);

        if(arr[n-1] <= sum){
            bool inc = solve(arr,sum - arr[n-1],n-1,table);
            if(inc || exc){
                table[n][sum] = 1;
            }else{
                table[n][sum] = 0;
            }
        }else{
            if(exc){
                table[n][sum] = 1;
            }else{
                table[n][sum] = 0;
            }
        }
        
        return table[n][sum];
    }
};