// https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        if(p.empty()) return true;
        vector<vector<int>> adj(numCourses);
        
        for(auto x : p){
            adj[x[0]].push_back(x[1]);
        }
        
        return topoSort(adj, numCourses);
    }
    
    bool topoSort(vector<vector<int>> &adj, int n){
        vector<int> in_dg(n, 0);
        
        for(int i = 0; i < n; i++){
            for(auto x : adj[i]){
                in_dg[x]++;
            }
        }
        
        queue<int> q;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            if(in_dg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(auto x : adj[node]){
                in_dg[x]--;
                if(in_dg[x] == 0){
                    q.push(x);
                }
            }
        }
        
        return count == n;
    }
};