// saurabhraj042
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        int m = a.size(), n = b.size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> res;
        
        if (m == 0 || n == 0) return res;
        
        for (int i = 0; i < m; i++) {
            pq.push({{a[i]+b[0]}, {i, 0}});
        }
        
        while (k-- && !pq.empty()) {
            int val = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            
            res.push_back({a[i], b[j]});
            if (j+1 == n) continue;
            
            pq.push({{a[i]+b[j+1]}, {i, j+1}});
        }
        return res;
    }
};

