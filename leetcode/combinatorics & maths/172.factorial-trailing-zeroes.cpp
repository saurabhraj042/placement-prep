// https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) {
        // Using High School maths for thi problem ^_^
        /*
            let n = 100, and formulae for finding the trailing zeros in 100!
            is :
                x = (100/5) + (100/5*5) + (100/5*5*5) + ....... +(100/5^p) 
                until the division gives zero we keep dividing n by 5^p ; p increases by 1
            
            since we can see that to find trailing zeros in a factorial we can simply divide
            the resultant number with 10 until the dividend is a integer

            and 10! = 1.2.3.4.5.6.7.8.9.10 we can see 10 appears twice in this seq,
            so instead of counting the 10s we can count 5 & 2 to keep track of 10s
            but keeping track of 2s is hard because it appears many times so we 
            decide to keep track of 5s

            video for ref : https://www.youtube.com/watch?v=fx8rUY_iIms

        */

       int count = 0;
       
       while(n){
            int t= n/5;
            count += t;
            n = t;
       }

       return count;
    }
};