// https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = size(nums1);
        int n = size(nums2);
        
        vector<int> res(m+n);
        int len = m+n;
        
        int i,j,idx;
        i = j = idx = 0;
        
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                res[idx++] = nums1[i++];
            }else{
                res[idx++] = nums2[j++];
            }
        }
        
        while(i < m){
            res[idx++] = nums1[i++];
        }
        
        while(j < n){
            res[idx++] = nums2[j++];
        }
        
        if(len % 2){
            return 1.0 * res[len/2];
        }else{
            double av = (res[len/2-1] + res[len/2]) /(double) 2;
            return 1.0 * av;
        }
    }
};