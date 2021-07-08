// https://leetcode.com/problems/count-number-of-nice-subarrays/
class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int B) {
        // Approach using HashTable only
        int count = 0;
        int sum=0;
        int n=A.size();
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)
        {
            sum += (A[i] % 2);
            
            if(sum==B)
            {
                count++;
            }
            
            if(mp.find(sum-B) != mp.end())
            {
                count+=mp[sum-B];
            }
            
            mp[sum]++;
        }
        return count;
    }
};

/*

*/