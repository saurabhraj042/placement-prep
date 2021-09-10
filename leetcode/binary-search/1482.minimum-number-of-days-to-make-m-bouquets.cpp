// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

/**
 * OBSERVATIONS :
 *                  # We can clearly see that if number of flowers < No. of BQ * Flowers in each BQ
 *                    then we can never make BQS of req quantity
 *                  # Let's assume the minimum blooming days required to make 'm' BQS is "X"
 *                    => X is lesser than the highest blooming day among the flowers
 *                    => X > 0, always
 *                    => 1 <= X <= MAX(bloomDay[i...n]) 
 *                    => If we check for every number in this range, like for ith number is it
 *                       possible to make 'm' BQS or not
 *                  # We can find this number either linearly iterating over the search space
 *                    or since it is monotonic in nature we can just applu BINARY SEARCH
 * 
 * DRY RUN :
 *              # a[] = [1,10,3,10,2],  M = 3,  K = 1
 *              => Now our search space is :    lo = 1  hi = 10
 *              => mid = 11 / 2 = 5
 *              => let's check how many BQS of size K we can make with blooming day = mid = 5
 *              => so, for      mid = 5     we can make 3 BQS {1}, {3}, {2}
 *                 i.e      no. of BQS (5) == M  , update ans to 5
 *              => now we even check for smaller blooming day to make M BQS
 *              
 *              # => lo = 1       hi = 5
 *              => mid = 6 / 2 = 3
 *              => BQS = {1}, {3}, {2} , update ans to 3
 *              
 *              # lo = 1    hi = 3
 *              => mid = 4 / 2 = 2
 *              => BQS = {1}, {2} , so for value = 2 we get BQS < M so we have to consider larger
 *              value and thus we go out of BINARY SEARCH loop
*/
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        return soln_1(bloomDay, m, k);
    }
    
   
    bool bouquetPossible(vector<int>& bloom_days, int bloom_day, int m, int k) {
        int bouquets = 0, flowers = 0;
        for(const int& day: bloom_days) {
            if(day <= bloom_day)
                ++flowers;
            else
                flowers = 0;
            if(flowers == k)
                ++bouquets, flowers = 0;
        }
        
        if(bouquets >= m) return 1;
        
        return false;
    }
    
    int soln_1(vector<int>& bloomDay, int m, int k) {
        if(m * k > bloomDay.size())
            return -1;
        
        int low = 0, high = INT_MIN;
        
        for(auto x : bloomDay) high = max(high, x);
        
        while(low < high) {

            int bloom_day = low + (high - low) / 2;
            
            if(bouquetPossible(bloomDay, bloom_day, m, k))
                high = bloom_day;
            else
                low = bloom_day + 1;
        }
        
        return high;
    }
};

