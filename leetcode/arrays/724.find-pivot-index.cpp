// https://leetcode.com/problems/find-pivot-index/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        return soln_2(nums);
    }
    
    // Brute force approach is simple and takes O(N^2)
    
    // Better approach used prefix sum and suffix sum techniques
    // O(N) time and O(2N) space
    
    int soln_1(vector<int> &a){
        size_t n = size(a);
        
        vector<int> pref_arr(n+2,0);
        vector<int> suff_arr(n+2,0);
        
        pref_arr[1] = a[0];
        suff_arr[n] = a[n-1];
        
        for(int i=2;i<n+2;i++){
            pref_arr[i] = a[i-1] + pref_arr[i-1];
        }
        
        for(int i=n-1;i>0;i--){
            suff_arr[i] = a[i-1] + suff_arr[i+1];
        }
        
        int pivot = -1;
        
        for(int i=1;i<=n;i++){
            int left_sum = pref_arr[i-1];
            int right_sum = suff_arr[i+1];
            
            if(left_sum == right_sum){
                pivot = i-1;
                break;
            }
        }
        
        return pivot;
    }
    
    // Optimal approach using a simple observation
    // O(N) : TC && O(1) : SC
    
    int soln_2(vector<int> &nums){
        int total = 0;
        size_t n = size(nums);
        for (int num : nums) total += num;
        
        int pref_sum = 0;
        
        for (int i = 0; i < n; pref_sum += nums[i++])
            if (pref_sum * 2 == total - nums[i])
                return i;
        
        return -1;
    }

    /*
        Let's say that for an index 'i' :
            left sum = a
            right sum = b
            total sum = T

            so => a + b + a[i] = T
        and it is given that for 'i' to be pivot a==b should be valid
        so let's assume that a==b for now

        => 2*a + a[i] = T so if this cond is valid we have our ans

        and here 'a' is nothing but prefix_sum till index 'i-1'
    */
};