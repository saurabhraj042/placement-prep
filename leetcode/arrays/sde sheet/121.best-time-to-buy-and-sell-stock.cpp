// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //int soln_bf = soln_1(prices);
        int soln_op = soln_2(prices);
        return soln_op;
    }
    
    // O(n^2)
    // Brute Force
    int soln_1(vector<int> &a){
        size_t n = size(a);
        int max_profit = 0;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int cur_profit = a[j] - a[i];
                max_profit = max(max_profit,cur_profit);
            }
        }
        
        return max_profit;
    }
    
    // O(n)
    // Optimal Approach
    
    int soln_2(vector<int> &a){
        int n = size(a);
        
        int sum_sofar = 0;
        int sum_tillhere = 0;
        
        for(int i=1;i<n;i++){
            sum_tillhere = max(0,sum_tillhere += a[i] - a[i-1]);
            sum_sofar = max(sum_sofar,sum_tillhere);
        }
        
        return sum_sofar;
    }
    
    /*
        A more clear explanation on why sum of subarray / Kadane Algo works.:

        Suppose we have original array:
        [a0, a1, a2, a3, a4, a5, a6]

        what we are given here(or we calculate ourselves) is:
        [b0, b1, b2, b3, b4, b5, b6]

        where,
        b[i] = 0, when i == 0
        b[i] = a[i] - a[i - 1], when i != 0

        suppose if a2 and a6 are the points that give us the max difference (a2 < a6)
        then in our given array, we need to find the sum of sub array from b3 to b6.

        b3 = a3 - a2
        b4 = a4 - a3
        b5 = a5 - a4
        b6 = a6 - a5

        adding all these, all the middle terms will cancel out except two
        i.e.

        b3 + b4 + b5 + b6 = a6 - a2

        a6 - a2 is the required solution.
    */
};