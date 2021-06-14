//saurabhraj042
// https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if( n==0 ) return 0;
        
        int mx=0,cnt=0;
        
        for(int i=0;i<n;i++){
            if( nums[i]==1 ){
                cnt++;
                mx = max(mx,cnt);
            }else{
                cnt=0;
            }
        }
        
        return mx;
    }
};

