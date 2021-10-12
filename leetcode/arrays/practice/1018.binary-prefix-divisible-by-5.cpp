// https://leetcode.com/problems/binary-prefix-divisible-by-5/
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int cur = 0;
        vector<bool> ans;
        
        for(auto x : nums){
            cur = ((cur * 2) % 5 + x) % 5;
            
            if(cur % 5 == 0) ans.push_back(true);
            else ans.push_back(false);
        }
        
        return ans;
    }
};