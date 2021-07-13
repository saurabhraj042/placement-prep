// https://leetcode.com/problems/excel-sheet-column-number/
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int n = s.length();
        
        for(char c:s){
            ans = ans*26 + (c - 'A') + 1;
        }
        return ans;
    }
};