// https://leetcode.com/problems/subarrays-with-k-different-integers/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
    
    int atmost(vector<int> &a,int k){
        int count = 0;
        int start = 0;
        unordered_map<int,int> mp;
        
        for(int end=0;end<a.size();end++){
            int e = a[end];
            mp[e]++;
            
            if(mp[e]==1) k--;
                        
            while(k < 0){
                int s = a[start];
                mp[s]--;
                
                if(mp[s]==0) k++;
                start++;
            }
            
            count += end - start + 1;
        }
        
        return count;
    }
};