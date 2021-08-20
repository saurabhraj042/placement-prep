// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        return soln_1(time);
    }
    
    // Hash-table approach
    int soln_1(vector<int> &a){
        unordered_map<int,int> mp;
        int count = 0;
        
        for(auto x:a){
            count += mp[(60 - x%60) % 60];
            mp[x%60]++;
        }
    
        return count;
    }
    
    /*  Find the reminder array first
        rem = 30,20,30,40,40
        
        for each a[i] just check if 60 - a[i] is there 
        or not ,if it's there then bingo their total sum
        becomes equals to 60 && 60%60 will give us 0 reminder
        
        *reason for (60 - t % 60) % 60 expression: If the map already has 30, we need to            look for the number is having remainder or not, this can be achieved with 60 -            t%60. Eg, if the number is 210. 60 - 210 % 60 returns 30. 30 is already in the            list this can be paired up to form (30,210).

        Reason for an extra % 60 over (60 - t % 60). if the t = 60, the expression 60 - t           % 60 returns 60. this is beyond our remainers range (0,59)for 60. to make it            with in the range in the case of 60 and multiples of 60, we are ufing an extra %60          on top of (60 - t % 60). this makes the remainder 0. which is with in the range             of remainders for 60(0,59)


    */
};