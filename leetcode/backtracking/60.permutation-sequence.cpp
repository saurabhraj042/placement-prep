// https://leetcode.com/problems/permutation-sequence/
class Solution {
public:
    string getPermutation(int n, int k) {
        string a = "";

        for(int i=1;i<=n;i++) a += to_string(i);
        
        soln_1(a,k);
        
        return a;
    }
    
    void soln_1(string &a, int k){
        for(int i=2; i<=k; i++){
            nextPermutation(a);
        }
    }
    
     void nextPermutation(string &a){
        int n = size(a);
        
        if(n == 1) return;
        
        int bp = -1;
         
        for(int i=n-1;i>0;i--){
            int cur = a[i] - '0';
            int pre = a[i-1] - '0';
            
            if(cur > pre){
                bp = i-1;
                break;
            }
        }
        
        if(bp == -1){
            reverse(begin(a),end(a));
            return;
        }
        
         int ele_bp = a[bp] - '0';
         
        for(int i=n-1;i>bp;i--){
            int cur = a[i] - '0';

            if(cur > ele_bp){
                swap(a[i],a[bp]);
                break;
            }
        }
        
       reverse(begin(a)+bp+1,end(a));
    }
};