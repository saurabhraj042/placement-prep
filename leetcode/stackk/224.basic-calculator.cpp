// https://leetcode.com/problems/basic-calculator/
class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        
        if(s.empty()) return 0;
        
        stack<int> stk;
        
        int cur = 0;
        int res = 0;
        int sign = 1;
        
        for(char c:s){
            if(c>='0' && c<='9'){
                // scanning the current  integer digit by digit
                cur = cur*10 + (c - '0');
                
            }else if(c=='+' || c=='-'){
                // add last scanned integer to the prev value 
                // sign is also taken into consideration
                res += cur*sign;
                // sign for next
                sign = (c=='+')?1:-1;
                cur = 0;
                
            }else if(c=='('){
                stk.push(res);
                stk.push(sign);
                
                // resetting variables
                res = 0;
                sign = 1;
                
            }else if(c==')'){
                res += cur*sign;
                cur = 0;
                int prev_sign = stk.top();stk.pop();
                int prev_val = stk.top();stk.pop();
                res *= prev_sign;
                res += prev_val;
            }
        }
        
        if(cur!=0) res += cur*sign;
        
        return res;
    }
};