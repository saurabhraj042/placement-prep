// author : saurabhraj
// user : saurabhraj042
// https://leetcode.com/problems/divide-two-integers
class Solution {
public:
    int divide(int a, int b) {
        if( a==INT_MIN && b==-1 ){
            return INT_MAX;
        }
        
        if( b==1 ) return a;
        
        int neg=1;
        if( a<0 && b<0 ) neg = 1;
        else if( a<0 || b<0 ) neg = -1;
        
        long ans = 0;
        long A = labs(a), B = labs(b);
        
        while( A >= B ){
            long cnt = 1;
            long t = B;
            
            while( t<< 1 <= A ){
                t <<= 1;
                cnt <<= 1;
            }
            
            A -= t;
            ans += cnt;
        }
        
        if( ans>INT_MAX || ans<INT_MIN ) return INT_MAX;
        return neg*ans;
    }
};

