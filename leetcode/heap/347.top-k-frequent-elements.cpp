// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto x:nums) mp[x]++;
        
        priority_queue<pair<int,int>> max_heap;
        
        for(auto x:mp){
            int val = x.first;
            int freq = x.second;
            
            max_heap.push({freq,val});
        }
        
        vector<int> ans;
        while(k != 0){
            k--;
            auto top = max_heap.top();
            max_heap.pop();
            ans.push_back(top.second);
        }
        
        return ans;
    }
};