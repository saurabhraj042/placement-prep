// https://leetcode.com/problems/koko-eating-bananas/
/**
 * # OBSERVATIONS :
 *                  * Let's say the max pile has X bananas, then if koko eats X b/hr then she can
 *                    eat all piles in 'N' hrs (N -> total no of piles of bananas)
 *                  * Now our task is to minimise this X, X is valid if koko can eat N piles completley
 *                    in H no. of hours
 *                  * We can see that X can have minim value of = 1;
 *                  * So now we have a range for possible values of X, i.e  
 *                          1 <= X <= N
 *                  * If we iterate through this range and find the minm valid value of X we will
 *                    have our answer or we can use BINARY SEARCH for finding the value;
 * # IsValid(int X) :
 *                  * For any value X it is valid if koko can eat all bananas under H hours of time
 * # DRY RUN :
 *              * p = [3, 6, 7, 11]    H = 8
 *              * lo = 1    hi = 11     => m = 12 / 2 = 6   => X = 6
 * * for X = 6 , hours needed = 1 + 1 + 2 + 2 = 6   i.e < H so this value is acceptable
 * * Now we can obviously try for smaller values of X so, lo = 1    hi = 6      => m = 7 / 2 = 3
 * * So  X = 3 , hours needed = 1 + 2 + 3 + 4 > H so we can't accept this value we need to inc it
 * * Thus we make  lo = 3   hi = 6 => X = 9 / 2 = 4
 * * for X = 4, hours needed = 1 + 2 + 2 + 3 < H so it is acceptable and fortunately our answer as well :)
 * 
 * */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return soln_2(piles, h);
    }

    int soln_1(vector<int> &p, int h){
        int lo = 1;
        int hi = 1000000000; // we can also take MAX element of piles but Since it is Binary Search it dosen't make much of a difference

        while(lo < hi){
            int m = (lo + hi) / 2;

            if(isValid(p, m, h)){
                hi = m;
            }else{
                lo = m + 1;
            }
        }

        return lo;
    }

    bool isValid(vector<int> &p, int m, int h){
        int totalHours = 0;
        
        for(int x : p){
            totalHours++;
            if(x > m){
                totalHours += x / m;
            }
        }

        return totalHours <= h;
    }
    
     int soln_2(vector<int>& piles, int H) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            for (int p : piles)
                total += (p + m - 1) / m;
            if (total > H)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};

