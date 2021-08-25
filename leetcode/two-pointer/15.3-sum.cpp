// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return soln_1(nums);
    }
    
    vector<vector<int>> soln_1(vector<int>& a) {
        int n = size(a);
        sort(begin(a),end(a));
        
        vector<vector<int>> ans;
        
        if(n < 3) return ans;
        
        for(int i=0;i<n-2;i++){
            if(i==0 || a[i] != a[i-1]){
                int sum = 0 - a[i];
                int lo = i+1;
                int hi = n-1;
                
                while(lo < hi){
                    if(a[lo] + a[hi] == sum){
                        ans.push_back({a[i],a[lo],a[hi]});
                        while(lo < hi && a[lo] == a[lo+1]) lo++;
                        while(lo < hi && a[hi] == a[hi-1]) hi--;
                        lo++;
                        hi--;
                    }else if(a[lo] + a[hi] < sum) lo++;
                    else hi--;
                }
            }
        }
        
        return ans;
    }
    
    
};