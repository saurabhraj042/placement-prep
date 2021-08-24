// https://leetcode.com/problems/global-and-local-inversions/
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        return soln_1(nums);
    }
    
    bool soln_1(vector<int> &a){
        int n = size(a);
        
        for(int i=0;i<n;i++){
            if(abs(a[i] - i) > 1) return false;
        }
        
        return true;
    }
    
    /*
        Global inversion (i<j and A[i] > A[j]) contains local inversions (A[i] > A[i+1]) because local inversions is a special case of global inversion where j = i+1.
For an array to have equal number of local and global inversions it should have just the local inversions.(because global inversions = {local inversion + cases where j > i+1} and for equality cases where j > i+1 should be zero.).
Now if we are given a sorted array like this {0,1,2,3,4,5} we have 0 local inversions in this as all elements are in increasing order and also note that elements index in a sorted array is element itself. i.e. A[i] = i. For creating a local inversion we will have to move a greater element at a position behind it but we cannot move more than 1 position because then we will end up creating cases where A[i] > A[j] for j > i+1 which we dont want.
So to check local inversions we just need to verify if in the given array element is shifted at most 1 position from its correct position in the sorted array.
    */
};