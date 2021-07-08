// https://leetcode.com/problems/count-number-of-nice-subarrays/
class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int B) {
        // Approach using Sliding window
        return atmost(A,B) - atmost(A,B-1);
    }
    
    int atmost(vector<int> a,int k){
        int count = 0;
        int start = 0;
        int end = 0;
        
        for(;end<a.size();end++){
            int x = a[end];
            
            k -= x%2;
            
            while(k < 0){
                int y = a[start];
                k += y%2;
                start++;
            }
            
            count += end - start + 1;
        }
        
        return count;
    }
};


/*
Here are some similar sliding window problems.
Also find more explanations.
Good luck and have fun.

Number of Substrings Containing All Three Characters
Count Number of Nice Subarrays
Replace the Substring for Balanced String
Max Consecutive Ones III
Binary Subarrays With Sum
Subarrays with K Different Integers
Fruit Into Baskets
Shortest Subarray with Sum at Least K
Minimum Size Subarray Sum

*/