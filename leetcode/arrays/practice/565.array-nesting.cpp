// https://leetcode.com/problems/array-nesting/
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        return soln_2(nums);
    }
    
    int soln_1(vector<int>& a) {
        int n = size(a);
        int mx = 0;
        
        for(int i=0;i<n;i++){
            int nextIdx = a[i];
            int cnt = 1;
            
            while(a[nextIdx] < n){
                nextIdx = a[nextIdx];
                cnt++;
            }
            
            if(cnt > mx){
                mx = cnt;
            }
        }
        
        return mx;
    }
    
    int soln_2(vector<int> a){
        int res = 0;
        vector<bool> seen(size(a));
        
        for(int i:a){
            int cnt = 0;
            
            while(!seen[i]){
                cnt++;
                seen[i] = 1;
                i = a[i];
            }
            
            res = max(res, cnt);
        }
        
        return res;
    }
};