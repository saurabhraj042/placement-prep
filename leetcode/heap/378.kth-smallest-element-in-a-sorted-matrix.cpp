// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        return soln_2(matrix,k);
    }
    
    // O(N^2 * logN) Max heap approach
    int soln_1(vector<vector<int>>& mat, int k){
        priority_queue<int> pq;
        
        size_t n = size(mat);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(mat[i][j]);
                
                while(size(pq) > k) pq.pop();
            }
        }
        
        
        return pq.top();
    }
    
    // Min heap apporach O(K * logN)
    int soln_2(vector<vector<int>> &mat,int k){
        int n = size(mat);
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        int p = min(n,k);
        
        for(int i=0;i < p;i++){
            pq.push({mat[i][0],i,0});
        }
        int ans;
        
        for(int i=0;i<k;i++){
            auto top = pq.top(); // ith smallest element
            pq.pop();
            
            int idx = top[2];
            ans = top[0];
            int row = top[1];
            
            if(idx+1 < n){
                pq.push({mat[row][idx+1],row,idx+1});
            }
        }
        
        return ans;
    }
};