// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
struct CompareHeapElements {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first<p2.first){
            return true;
        }
        else if(p1.first==p2.first && p1.second<p2.second){
            return true;
        }
        return false;
    }
};

class Solution {
    int calculateSoldierCount(vector<int>& v) {
        int l = 0; 
        int h = v.size() - 1;
        
        while(l <= h) {
            int mid = l + (h - l) / 2;
            
            if(v[mid] == 0) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements> max_heap;
        
       
        for(int i=0;i<mat.size();++i){
            max_heap.push({calculateSoldierCount(mat[i]),i});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        
        vector<int>ans;
        while(max_heap.size()){ 
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
		
        reverse(ans.begin(), ans.end());
        return ans;
    }
};