// https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        soln_1(nums,k);
    }
    
    // Two pointer O(N) approach
    void soln_1(vector<int> &a,int k){
        int n = size(a);
        int pass = 1;
        int start = 0;
        int cur = 0;
        int nex = 0;
        int prev = a[cur];
        
        while(pass <= n){
            do{
                nex = (cur + k)%n;
                int temp = a[nex];
                a[nex] = prev;
                prev = temp;
                cur = nex;
                pass++;
            } while(start != cur);
            
            start++;
            cur = start;
            prev = a[cur];
        }
    }
};