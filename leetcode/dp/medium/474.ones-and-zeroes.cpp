// https://leetcode.com/problems/ones-and-zeroes/
class Solution {
public:
    int arr[601][101][101];
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        memset(arr, -1, sizeof(arr));
        return solve(strs,len,m,n);
    }
    
    int solve(vector<string> &a,int len,int m,int n){
        if(len==0) return 0;
        
        if(arr[len][m][n] != -1) return arr[len][m][n];
        
        int z,o;
        z = o = 0;
        
        for(auto x:a[len-1]){
            if(x=='1') o++;
            else z++;
        }
        
        if(z<=m && o<=n) arr[len][m][n] = max(1 + solve(a,len-1,m-z,n-o),solve(a,len-1,m,n));
        else arr[len][m][n] = solve(a,len-1,m,n);
        
        return arr[len][m][n];
    }
};