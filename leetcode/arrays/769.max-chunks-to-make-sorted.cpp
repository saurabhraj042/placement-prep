// https://leetcode.com/problems/max-chunks-to-make-sorted/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        return soln_1(arr);
    }
    
    int soln_1(vector<int> &a){
        int mx = 0;
        int ans = 0;
        
        for(int i=0;i<a.size();i++){
            mx = max(mx,a[i]);

            if(mx == i){
                ans++;
            }
        }
        
        return ans;
    }
    
    /*
        The basic idea is to use max[] array to keep track of the max value until the current position, and compare it to the sorted array (indexes from 0 to arr.length - 1). If the max[i] equals the element at index i in the sorted array, then the final count++.

        Update: As @AF8EJFE pointed out, the numbers range from 0 to arr.length - 1. So there is no need to sort the arr, we can simply use the index for comparison. Now this solution is even more straightforward with O(n) time complelxity.

        For example,

        original: 0, 2, 1, 4, 3, 5, 7, 6
        max:      0, 2, 2, 4, 4, 5, 7, 7
        sorted:   0, 1, 2, 3, 4, 5, 6, 7
        index:    0, 1, 2, 3, 4, 5, 6, 7
        The chunks are: 0 | 2, 1 | 4, 3 | 5 | 7, 6
    */
};