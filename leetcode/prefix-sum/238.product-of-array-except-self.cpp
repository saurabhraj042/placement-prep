// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        return soln_1(nums);
    }
    
    // Optimal using prefix and suffix sum
    vector<int> soln_1(vector<int>& a) {
        size_t n = size(a);
        vector<int> ans(n,1);
        
        for(int i=1;i<n;i++){
            ans[i] = a[i-1] * ans[i-1];
        }
        
        int cur_right = 1;
        for(int i=n-1;i>=0;i--){
            if(i < n-1){
                // update the current right product
                cur_right *= a[i+1];
            }
            ans[i] *= cur_right;
        }
        
        return ans;
    }
    
    /*
        Given numbers [2, 3, 4, 5], regarding the third number 4, 
        the product of array      
        except 4 is 2*3*5 which consists of two parts: left 2*3 and right 5. 
        The product is l left*right. We can get lefts and rights:

            Numbers:     2    3    4     5
            Lefts:            2  2*3 2*3*4
            Rights:  3*4*5  4*5    5      
            Let’s fill the empty with 1:

            Numbers:     2    3    4     5
            Lefts:       1    2  2*3 2*3*4
            Rights:  3*4*5  4*5    5     1
            We can calculate lefts and rights in 2 loops. The time complexity is O(n).

        We store lefts in result array. If we allocate a new array for rights. 
        The space complexity is O(n).
        To make it O(1), we just need to store it in a variable which is right in @lycjava3’s code.
    /
};