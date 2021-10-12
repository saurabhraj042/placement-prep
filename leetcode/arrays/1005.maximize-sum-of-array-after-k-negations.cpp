// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& a, int k) {
        int n = size(a);
        sort(begin(a), end(a));

        for(int i = 0; i < n && k > 0; i++){
            if(a[i] < 0){
                a[i] *= -1;
                k--;
            }
        }
        
        
        if(k % 2 && k > 0){
            int i_min = 0;
            
            for(int i = 0; i < n; i++){
                if(a[i_min] > a[i]){
                    i_min = i;
                }
            }
            
            a[i_min] = -a[i_min];
        }
        
        int ans = 0;
        
        for(auto x : a) ans += x;
        
        return ans;
    }
};