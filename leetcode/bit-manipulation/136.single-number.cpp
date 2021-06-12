// author : saurabhraj
// user : saurabhraj042
// https://leetcode.com/problems/single-number
class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        
        for(int i=0;i<n;i++){
            ans ^= a[i];
        }
        
        return ans;
    }
};

