class Solution {
public:
    double myPow(double x, int n) {
        long long  nn = n;
        if(n<0) nn *= -1;
        
        double ans = 1.0;
        
        while(nn){
            if(nn&1){
                ans *= x;
                nn -= 1;
            }else{
                x *= x;
                nn >>= 1;
            }
                
        }
        
        if(n<0) return( (double)1.0/(double)ans );
        
        return ans;
    }
};