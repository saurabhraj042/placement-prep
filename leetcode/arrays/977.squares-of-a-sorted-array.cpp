// https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        return soln_1(nums);
    }
    
    // Optimal solution uses Merge Sort technique
    // TC : O(N) && SC : O(N);
    vector<int> soln_1(vector<int> &a){
        size_t n = size(a);
        int part_idx = -1;
        
        for(int i=0;i<n;i++){
            if(a[i] >= 0){
                part_idx = i;
                break;
            }
        }
        compute_sq(a,0,n-1);

        if(part_idx == -1){
            reverse(begin(a),end(a));
            return a;
        }
        
        vector<int> ans(n);
        int i = part_idx -1;
        int j = part_idx;
        int idx = 0;
        
        while(i>=0 && j<n){
            if(a[i] < a[j]){
                ans[idx] = a[i];
                i--;
            }else{
                ans[idx]= a[j];
                j++;
            }
            idx++;
        }
        
        while(i >= 0){
            ans[idx++] = a[i--];
        }
        
        while(j < n){
            ans[idx++] = a[j++];
        }
        
        return ans;
    }
    
    void compute_sq(vector<int> &a,int s,int e){
        for(int i=s;i<=e;i++){
            a[i] *= a[i];
        }
    }
};