// author : saurabhraj
// user : saurabhraj042
// https://leetcode.com/problems/total-hamming-distance
class Solution {
public:
    int totalHammingDistance(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        
        for(int i=0;i<32;i++){
            int c = 0;
            
            for(int j=0;j<n;j++){
                
                if( a[j] & (1<<i) ){
                    c++;
                }
            }
            
            ans += c * (n - c);
        }
        
        return ans;
    }
};

