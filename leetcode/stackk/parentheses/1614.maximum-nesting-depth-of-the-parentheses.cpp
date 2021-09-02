// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
class Solution {
public:
    int maxDepth(string s) {
        return soln_2(s);
    }
    
    // Approach using stack
    // Intution : To find the nesting degree we can just keep count
    // of the current open brackets, max depth will be equal to the no
    // of open parentheses
    
    int soln_1(string s){
        stack<int> stk;
        int ans = 0;
        for(auto c : s){
            if(c == '('){
                stk.push(1);
                int k = stk.size();
                ans = max(ans, k);
            }else if(c == ')'){
                stk.pop();
            }
        }
        
        return ans;
    }
    
    // Optimal
    int soln_2(string s){
        int ans = 0, cur = 0;
        for(auto c:s){
            if(c == '('){
                cur++;
                ans = max(ans, cur);
            }else if(c == ')'){
                cur--;
            }
        }
        return ans;
    }
    
};