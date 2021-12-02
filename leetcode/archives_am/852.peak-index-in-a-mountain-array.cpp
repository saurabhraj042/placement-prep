// https://leetcode.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int l = 0;
        int h = size(a) - 1;
        
        while(l < h){
            int m = (l + h) / 2;
            
            if(a[m] < a[m+1]){
                l = m + 1;
            } else {
                h = m;
            }
        }
        
        return l;
    }
};