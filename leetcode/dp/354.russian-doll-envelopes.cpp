class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Samjh ni aaya vro :(
        
        sort(begin(envelopes), end(envelopes),
         [](const vector<int> &p1, const vector<int> &p2) {
           return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1]);
         });
        vector<int> dp;
        
        for (auto &envelop : envelopes) {
            
            auto it = lower_bound(begin(dp), end(dp), envelop[1]);
              
            if (it == end(dp)) {
                dp.emplace_back(envelop[1]);
              } else if (*it > envelop[1]) {
                *it = envelop[1];
              }
        }
        return dp.size();    
    }
    
    
};