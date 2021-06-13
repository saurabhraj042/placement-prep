// author : saurabhraj
// user : saurabhraj042
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if( n==0 ) return 0;
        int index = 0;

        for(int i=0;i<n-1;i++){

            if( nums[i+1]!=nums[i] ){
                index++;
                nums[index] = nums[i+1];
            }
        }

        return index+1;
    }
};

