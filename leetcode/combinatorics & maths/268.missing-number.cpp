// https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        size_t n = nums.size();
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = ans^i;
        }
        
        for(int i=0;i<n;i++){
            ans = ans ^ nums[i];
        }
        
        return ans;
    }
    
   
};