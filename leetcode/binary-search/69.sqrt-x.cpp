// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/sqrtx/description/
class Solution {
public:
    int mySqrt(int x) {

        if(x==0) return 0;

        if(x==1||x==2) return 1;

        int l=1,r=x;
        int ans;

        while(l<=r){
            int mid = l + (r-l)/2;

            if( mid>x/mid){
                r = mid-1;
            }else{
                ans = mid;
                l = mid+1;
            }
        }

        return ans;
    }
};

