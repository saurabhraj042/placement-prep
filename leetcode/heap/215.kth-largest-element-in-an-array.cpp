// saurabhraj042
// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto x:nums){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }

        return pq.top();
    }
};

