// https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = size(nums) - 2;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            
            if(mid % 2){
                // odd index
                if(nums[mid - 1] != nums[mid]){
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                // even index
                if(nums[mid + 1] != nums[mid]){
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        
        return nums[lo];
    }
};