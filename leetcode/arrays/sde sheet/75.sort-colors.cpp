class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo=0,mid=0,hi=(nums.size())-1;
        
        while(mid<=hi){
            int c = nums[mid];
            
            if( c==0 ){
                swap( nums[mid],nums[lo] );
                mid++;
                lo++;
            }else if( c==1 ){
                mid++;
            }else{
                swap( nums[mid],nums[hi] );
                hi--;
            }
        }
        
    }
};