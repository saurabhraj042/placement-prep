// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        return soln_1(nums, threshold);   
    }
    
  
    
    int soln_1(vector<int> &A, int threshold){
        int left = 1, right = 1e6, m, sum;
        
        while (left < right) {
            m = (left + right) / 2, sum = 0;
            
            for (int i : A)
                sum += (i + m - 1) / m;
            
            if (sum > threshold)
                left = m + 1;
            else
                right = m;
        }
        return left;
    }
};