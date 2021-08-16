// https://leetcode.com/problems/subarray-sums-divisible-by-k/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        return soln(nums,k);
    }
    
    // Brute force 
    // O(N^2)
    int soln_1(vector<int> &a,int k){
        size_t n = size(a);
        int count = 0;
        int pref_sum[n];
        pref_sum[0] = a[0];
        for(int i=1;i<n;i++) pref_sum[i] = pref_sum[i-1] + a[i];
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = pref_sum[j] - pref_sum[j];
                if(sum%k == 0){
                    count++;
                }
            }
        }
        
        return count;
    }
    
    // Optimal 
    // O(N)
    int soln(vector<int> &a,int k){
        int pref_sum = 0;
        size_t n = size(a);
        unordered_map<int,int> mp;
        int count = 0;
        mp[0] = 1;
        
        for(int i=0;i<n;i++){
            pref_sum += a[i];
            int rem = pref_sum % k;
            
            if(rem < 0) rem += k;
            count += mp[rem]++; 
            /*
                if sum[0, i] % K == sum[0, j] % K, sum[i + 1, j] is divisible by by K.
                So for current index j, we need to find out how many indexes p (p < j)                   exit that has the same mod of K.
            */
        }
        
       
        return count;
    }
};