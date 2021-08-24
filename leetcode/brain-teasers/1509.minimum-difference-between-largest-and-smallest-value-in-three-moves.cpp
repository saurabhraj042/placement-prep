// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
class Solution {
public:
    int minDifference(vector<int>& nums) {
        return soln_2(nums);
    }
    
    // Brute force with TC : O(NlogN) and SC : (N^2)
    int soln_1(vector<int> &a){
        sort(begin(a),end(a));
        
        int n = size(a);
        vector<int> p;
        vector<int> q;
        int mx = INT_MIN;
        int mn = INT_MAX;
        
        for(auto x:a){
            mx = max(mx,x);
            mn = min(mn,x);
            p.push_back(x);
            q.push_back(x);
        }
        
        for(int i=0;i<3 && i<n;i++){
            p[i] = mx;
        }
        for(int i=n-1;i>n-4 && i>=0;i--){
            q[i] = mn;
        }
        
        sort(begin(p),end(p));
        sort(begin(q),end(q));
        
        int d1 = p[n-1] - p[0];
        int d2 = q[n-1] - q[0];
        
        return min(d1,d2);
    }
    
    // Optimal with constant space
    
    int soln_2(vector<int> &a){
        sort(begin(a),end(a));
        size_t n = size(a);
        if (n < 5) return 0;
        int ans = min({a[n-1]-a[3],a[n-4]-a[0],a[n-2]-a[2],a[n-3]-a[1]});
        return ans;
    }
    
    /*
        
    */
};