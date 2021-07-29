// https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Two pointers
        int x = s.length();
        int y = t.length();
        
        int i=0,j=0;
        
        while(i<x && j<y){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        
        return i==x;
    }
};