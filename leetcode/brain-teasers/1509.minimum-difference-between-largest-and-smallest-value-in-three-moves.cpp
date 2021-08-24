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
 

Intuition
If we can do 0 move, return max(A) - min(A)
If we can do 1 move, return min(the second max(A) - min(A), the max(A) - second min(A))
and so on.


Explanation
We have 4 plans:

kill 3 biggest elements
kill 2 biggest elements + 1 smallest elements
kill 1 biggest elements + 2 smallest elements
kill 3 smallest elements

Example from @himanshusingh11:

A = [1,5,6,13,14,15,16,17]
n = 8

Case 1: kill 3 biggest elements

All three biggest elements can be replaced with 14
[1,5,6,13,14,15,16,17] -> [1,5,6,13,14,14,14,14] == can be written as A[n-4] - A[0] == (14-1 = 13)

Case 2: kill 2 biggest elements + 1 smallest elements

[1,5,6,13,14,15,16,17] -> [5,5,6,13,14,15,15,15] == can be written as A[n-3] - A[1] == (15-5 = 10)

Case 3: kill 1 biggest elements + 2 smallest elements

[1,5,6,13,14,15,16,17] -> [6,6,6,13,14,15,16,16] == can be written as A[n-2] - A[2] == (16-6 = 10)

Case 4: kill 3 smallest elements

[1,5,6,13,14,15,16,17] -> [13,13,13,13,14,15,16,17] == can be written as A[n-1] - A[3] == (17-13 = 4)

Answer is minimum of all these cases!
    */
};