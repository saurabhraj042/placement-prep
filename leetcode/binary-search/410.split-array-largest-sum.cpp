// https://leetcode.com/problems/split-array-largest-sum/
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        return soln_1(nums, m);
    }

    int soln_1(vector<int> &a, int m){
        int l = 0;
        int r = 0;
        for(auto x : a){
            l = max(l, x);
            r += x;
        }
        long long mid, sum, count;

        while(l < r){
            mid = l + (r - l) / 2;
            sum = 0, count = 1;

            for(int  x : a){
                sum += x;
                if(sum > mid){
                    sum = x;
                    count++;
                }
            }

            if(count > m){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return l;
    }
};


