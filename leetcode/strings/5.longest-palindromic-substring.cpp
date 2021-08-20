// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution {
public:
    string longestPalindrome(string s) {
        return soln_3(s);
    }
    
    // Top Down DP
    string soln_1(string s){
        string ans = "";
        size_t n = size(s);
        int max_len = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[i] == s[j] && isPalin(s,i,j,dp)){
                    int len = j - i + 1;
                    if(len > max_len){
                        max_len = len;
                        ans = s.substr(i,j+1);
                    }
                }
            }
        }
        
        return ans;
    }
    
    bool isPalin(string &s,int i,int j,vector<vector<int>> &dp){
        if(i >= j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] != s[j]){
            return dp[i][j] = 0;
        }
        
        if(j - i <= 2){
            return dp[i][j] = 1;
        }
        
        return dp[i][j] = isPalin(s,i+1,j-1,dp);
    }
    
    
    // Bottom up DP
    string soln_2(string s) {
        size_t n = size(s);
        
        if (n <= 1) return s;
        
        vector<vector<bool>> dp(n,vector<bool>(n));
        
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        
        int s_long = 0, max_len = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int e = i + 1; e < n; e++) {
                if (s[i] == s[e]) {
                    if (e - i == 1 || dp[i + 1][e - 1]) {
                        dp[i][e] = true;
                        if (max_len < e - i + 1) {
                            s_long = i;
                            max_len = e - i + 1;
                        }
                    }
                }

            }
        }
        
        return s.substr(s_long, s_long + max_len);
    }
    
    // Best Approach
    string soln_3(string &s)
    {
        int len = s.length();
        if (len == 1)
            return s;
        int start = 0;
        int mx = 1;

        for (int i = 0; i < len;)
        {
            int left = i - 1;
            int right = i + 1;

            //skip the duplicates both on right 

            while (right < len && s[right] == s[i])
            {
                right++;
            }

            i = right;

            // check for the palindrome *Exanpding*

            while (left >= 0 && right < len && s[left] == s[right])
            {
                left--;
                right++;
            }

            // checking for the length of palindrome if found
            right--;left++;
            int newLen = right - left + 1;

            if (newLen > mx)
            {
                start = left;
                mx = newLen;
            }
        }

        return s.substr(start, mx);
    }
};