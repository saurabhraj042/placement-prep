// https://leetcode.com/problems/relative-ranks/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq;
        unordered_map<int,int> mp;
        int rank = 1;
        
        for(auto x : score) pq.push(x);
        
        while(!pq.empty()){
            mp[pq.top()] = rank;
            pq.pop();
            rank++;
        }
        
        vector<string> ans;
        
        for(auto x : score){
            int rank = mp[x];
            
            if(rank == 1) ans.push_back("Gold Medal");
            else if (rank == 2) ans.push_back("Silver Medal");
            else if (rank == 3) ans.push_back("Bronze Medal"); 
            else ans.push_back(to_string(rank));
        }
        
        return ans;
    }
};