// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/number-of-1-bits/description/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n>0){
            n &= (n-1);
            ans++;
        }
        return ans;
    }
};

