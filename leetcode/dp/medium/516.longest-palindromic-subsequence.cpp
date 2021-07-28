// https://leetcode.com/problems/longest-palindromic-subsequence/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string d = s;
        reverse(d.begin(),d.end());
        
        
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1));
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=s.length();j++){
                
                if(s[i-1] == d[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // for printing longest common subsequence
        int i=n,j=m;
        while(i>0 && j>0){    // if any of this i and j becomes 0 means one string is empty 
            if(x[i-1]==y[j-1]){
                s+=x[i-1];    //if character matches then add that to result string and move diagonally up
                i--;j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j])j--;    // else find the max of up and right position of dp table and move accordingly to up or left
                else i--;
            }
        }
        reverse (s.begin(),s.end());    // reverse the string as we started from last
        cout<<s;
        // watch Aditya Verma if not understood the printing part
        
        return dp[s.length()][s.length()];
    }

};