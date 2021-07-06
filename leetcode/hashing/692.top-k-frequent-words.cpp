// https://leetcode.com/problems/top-k-frequent-words/
class Solution {
public:
    struct Comp {
        Comp() {}
        ~Comp() {}
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) {
            return a.first<b.first || (a.first==b.first && a.second>b.second);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,Comp> heap;
        
        
        for(auto x:words) mp[x]++;
        
        for(auto x:mp){
            auto word = x.first;
            auto freq = x.second;
            
            heap.push({freq,word});
        }
        
        while(k--){
            auto top = heap.top();
            heap.pop();
            ans.push_back(top.second);
        }
        
        return ans;
    }
};