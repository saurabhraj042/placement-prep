// saurabhraj042
// https://leetcode.com/problems/max-consecutive-ones-iii/
class Solution {
public:
    int longestOnes(vector<int>& a, int b) {
        int n = a.size();
        int len = 0;
        int j = -1;
        int count  = 0;

        for(int i=0;i<n;i++){

            if( a[i]==0 ) count++;

            while( count > B ){
                j++;
                if( a[j]==0 ) count--;
            }

            len = max( len,i-j );
        }
        return len;
    }
};

