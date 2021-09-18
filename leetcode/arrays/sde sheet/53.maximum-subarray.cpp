class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int max_till_here = 0;
        
        for(int i=0;i<nums.size();i++){
            max_till_here += nums[i];
            max_so_far = max( max_so_far,max_till_here );
            if( max_till_here < 0) max_till_here = 0;
        }
        
        return max_so_far;
        
    }
};