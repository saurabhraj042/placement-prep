// https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = size(nums);
        return soln_2(nums, n);
    }
    
    int soln_1(vector<int> &a, int n,int prod){
        if(n == 1) return prod*a[n-1];
        
        
        int inc = soln_1(a,n-1,prod*a[n-1]);
        int exc = soln_1(a,n-1,1);
        
        return max(inc, exc);
    }
    
    
    // https://www.youtube.com/watch?v=lXVy6YWFcRM
    int soln_2(vector<int> &A,int n){
        int r = A[0];
        int imax = r;
        int imin = r;
        
        for (int i = 1; i < n; i++) {
        
            if (A[i] < 0)
                swap(imax, imin);

            imax = max(A[i], imax * A[i]);
            imin = min(A[i], imin * A[i]);

            r = max(r, imax);
        }
        return r;
    }
};