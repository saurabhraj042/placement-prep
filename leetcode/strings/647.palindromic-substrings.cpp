// https://leetcode.com/problems/palindromic-substrings/
/*
    This ques is similar to 
    https://github.com/saurabhraj042/placementprep/blob/main/leetcode/strings/5.longest-palindromic-substring.cpp
*/
class Solution {
public:
    int countSubstrings(string s) {
        return soln_2(s);
    }
    
    /*  Brute force approach will be to generate all the substrings
        which will take O(N^2) time and for each substring we check
        if it is a palindrome which takes O(N) time
        so TC = O(N^3)
    */
    
    // Recursive + Memo approach O(N^2)
    int soln_1(string s){
        int count = 0;
        size_t n = size(s);
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j,dp)){
                    count++;
                }
            }
        }
        return count;
    }
    
    bool isPalindrome(string s,int i,int j,vector<vector<int>> &dp){
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = s[i] == s[j] ? isPalindrome(s,i+1,j-1,dp) : 0;
    }
    
    // Tabulation
    int soln_2(string s){
        int count = 0;
        size_t n = size(s);
        vector<vector<bool>> dp(n,vector<bool>(n));
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                dp[i][j] = (s[i] == s[j]) && (j-i+1 < 3 || dp[i+1][j-1]);
                if(dp[i][j]) count++;
            }
        }
        return count;
        
    }
};