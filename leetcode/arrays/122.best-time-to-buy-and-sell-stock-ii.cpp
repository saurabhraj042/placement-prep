// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 0;
        size_t n = prices.size()-1;
        
        while(i < n){
            
            while(i < n && prices[i] >= prices[i+1]) i++;
            int buy = prices[i];
            
            while(i < n && prices[i] < prices[i+1]) i++;
            int sell = prices[i];
            
            profit += sell - buy;
        }
        
        return profit;
    }
};