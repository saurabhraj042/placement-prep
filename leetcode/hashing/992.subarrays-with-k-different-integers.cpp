// https://leetcode.com/problems/subarrays-with-k-different-integers/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
    
    int atmost(vector<int> &a,int k){
        int count = 0;
        int start = 0;
        unordered_map<int,int> mp;
        
        for(int end=0;end<a.size();end++){
            int e = a[end];
            mp[e]++;
            
            if(mp[e]==1) k--;
                        
            while(k < 0){
                int s = a[start];
                mp[s]--;
                
                if(mp[s]==0) k++;
                start++;
            }
            
            count += end - start + 1;
        }
        
        return count;
    }
};



/*
The intuition behind atMostK(A, K) - atMostK(A, K - 1);:

This problem is a hard ask, until you realize that we've actually solved this problem before in other sliding window problems. Generally, the sliding window problems have some kind of aggregate, atMost k, largest substring, min substring with k etc. They're always "given an array or string, find some computed sub problem" value.

So how do we use this our advantage? Well, the ask: different integers in that subarray is exactly K is exactly this. We can rewrite the problem to something like this:

subArrayExactlyK = subArrayAtMostK - subArrayAtMostK - 1. This is basically saying, give me the amount of subarrays we can form with at least 3, and give me the amount of subarrays we can form with at least 2, and the diff between the two will be only subarrays at 3 (since we have eliminated everything 2 and under).

Example:
Input: A = [1,2,1,2,3], K = 2
Output: 7

subArrayAtMostK = 12
if k = 2, there are 12 possible subarrays that are at least 2 values.
This is the array possibilities we create, where the count is the end - start (see below code example), since a sub problem will contribute to the overall amount of possibilities. You see below for the AtMostK problems if this concept is confusing. The other trick here is that in other atMostK problems, they ask for length, but length can also be a substitute for amount of sub problems, since the length of any given range, say 1212, also constitutes 4 different subarray possibilities.
[1, 12, 121, 1212, 23]

1 + 2 + 3 + 4 + 2 = 12

subArrayAtMostK - 1 = 5
since k = 1, every subarray is a single element, so the length of the array. There are by definition, only 5 different subarrays that can be formed.
[1, 2, 1, 2, 3]
1 + 1 + 1 + 1 + 1 = 5

So the amount of subarrays possible with at least 2 - the amount of subarrays with at least 1 = the exactly subarrays that contain only 2, since we have stripped out answers with only 1.

12 - 5 = 7;


*/