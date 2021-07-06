// https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        
        for(char c:s) mp[c]++;
        
        for(auto x:mp){
            auto value = x.first;
            auto freq = x.second;
            pq.push({freq,value});
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int freq = top.first;
            char val = top.second;
            
            while(freq--) ans += val;
        }
        
        return ans;
    }
};