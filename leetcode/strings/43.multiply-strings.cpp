// https://leetcode.com/problems/multiply-strings/
// https://leetcode.com/problems/multiply-strings/discuss/1563536/C%2B%2B-Simple-Solution-w-Explanation-and-Images-or-School-%2B-Optimized-Multiplication
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string ans = "";
        int m = num1.length();
        int n = num2.length();
        vector<int> res(m+n, 0);
        
        for(int i=m-1; i >= 0; i--){
            for(int j=n-1; j >= 0; j--){                
                int prod = (num1[i] - '0') * (num2[j] - '0');
                
                res[i + j + 1] += prod; 
                
                res[i + j] += res[i + j + 1] / 10;
                
                res[i + j + 1] %= 10; 
            }
        }
        
        
        int i = 0;
        while(i < m + n && res[i] == 0) i++;
        
        while(i < m + n ) ans += (res[i++] + '0'); // + op coz we are converting into to char
        
        return ans;
    }
};