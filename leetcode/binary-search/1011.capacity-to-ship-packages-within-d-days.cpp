// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        return soln_1(weights, days);
    }
    
    int soln_1(vector<int> &a, int d){
        int start = 0, end = 0, sum, count;
        for(auto x : a){
            start = max(start, x);
            end += x;
        }
        
        while(start < end){
            int mid = start + (end - start) / 2;
            sum = 0, count = 1;
            
            for(auto x : a){
                sum += x;
                if(sum > mid){
                    sum = x;
                    count++;
                }
            }
            
            if(count > d){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        
        return start;
    }
};