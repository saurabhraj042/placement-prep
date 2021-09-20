// https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& a) {
        soln_1(a);
    }
    
    // O(N)
    void soln_1(vector<int> &a){
        int n = size(a);
        
        if(n == 1) return;
        
        int bp = -1;
        for(int i=n-1;i>0;i--){
            if(a[i] > a[i-1]){
                bp = i-1;
                break;
            }
        }
        
        if(bp == -1){
            reverse(begin(a),end(a));
            return;
        }
        
        for(int i=n-1;i>bp;i--){
            if(a[i] > a[bp]){
                swap(a[i],a[bp]);
                break;
            }
        }
        
       reverse(begin(a)+bp+1,end(a));
    }
};