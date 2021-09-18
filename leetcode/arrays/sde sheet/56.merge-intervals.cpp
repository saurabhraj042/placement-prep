class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(begin(a), end(a));
        vector <vector <int> > ans;
        vector <int> temp = a[0];
        
        for (auto x : a){
            if (x[0] <= temp[1]) {
                // Overlapping condition
                temp[1] = max(temp[1], x[1]);
            } else {
                // Current interval doesn't overlap
                ans.push_back(temp);
                temp = x;
            }
        }
        
        ans.push_back(temp);
        
        return ans;
    }
};