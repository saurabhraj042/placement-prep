// https://leetcode.com/problems/basic-calculator-ii/
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int cur = 0;
        int res = 0;
        char sign = '+';
        s += '+';
        
        for(char c:s){
            if(c>='0' && c<='9'){
                
                cur = cur*10 + (c - '0');
                
            }
            
            if(c=='+' || c=='-' || c=='*' || c=='/'){
                
                if(sign == '+'){
                    
                    stk.push(cur);
                    
                }else if(sign == '-'){
                    
                    stk.push(-cur);
                    
                }else if(sign == '*'){
                    
                    auto pre = stk.top();
                    stk.pop();
                    stk.push(cur * pre);
                    
                }else if(sign == '/'){
                    
                    auto pre = stk.top();
                    stk.pop();
                    stk.push(pre / cur);
                    
                }

                sign = c;
                cur = 0;
            }
        }
        
        res += cur;
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
       
        return res;
    }
};