// https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    bool isPalindrome(string s,int low,int high){
        while(low <= high){
            if(s[low++] != s[high--]) return false;
        }
        return true;
    }
    
    void backtrack(string s,vector<vector<string>> &ans,vector<string> &temp,int start){
        if(start == s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=start;i<s.length();i++){
            
            if(isPalindrome(s,start,i)){
                int len = i - start + 1; // ***
                
                temp.push_back(s.substr(start,len));
                
                backtrack(s,ans,temp,i+1);
                
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(s,ans,temp,0);
        return ans;
    }
};