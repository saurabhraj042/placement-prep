class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        return soln (nums, n);
    }
    
    // Optimal Approach
    vector<int> soln (vector<int> &a, int n) {
        for (int i = n; i < 2 * n; i++) {
            a[i] = (a[i] * 1024) + a[i - n];
        }
        
        int idx = 0;
        for (int i = n; i < 2 * n; i++, idx += 2) {
            a[idx] = a[i] % 1024;
            a[idx + 1] = a[i] / 1024;
        }
        
        return a;
    }
};