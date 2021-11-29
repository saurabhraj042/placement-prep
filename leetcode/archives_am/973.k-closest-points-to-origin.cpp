// https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < points.size(); i++){
            auto pt = points[i];
            long long int x_sq = pt[0] * pt[0];
            long long int y_sq = pt[1] * pt[1];
            
            int dis_og = (x_sq + y_sq);
            
            pq.push({dis_og, i});
        }
        
        while(k-- && !pq.empty()){
            auto pt = pq.top();
            pq.pop();
            
            ans.push_back(points[pt.second]);
        }
        
        return ans;
    }
};