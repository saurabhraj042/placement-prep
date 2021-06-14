// saurabhraj042
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& A) {
        int i = 0,j = A.size()-1;
        int mx = j * min( A[i],A[j] );
        
        while( i < j )
        {
            if( (j-i) * min( A[j],A[i] ) > mx)
                mx=(j-i)*min(A[j],A[i]);
            
            if( A[i] < A[j]) i++;
            else j--;
        }
        return mx;
    }
};

