// https://leetcode.com/problems/decode-string/
class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return soln_2(s);
    }
    
    // Recursion approach
    string soln_1(string s,int &pos){
        size_t n = size(s);
        int num = 0;
        string word = "";
        
        for(;pos < n;pos++){
            if(s[pos] == '['){
                pos += 1;
                string temp = soln_1(s,pos);
                for(;num > 0;num--) word += temp;
            }else if(s[pos] == ']'){
                return word;
            }else if(isdigit(s[pos])){
                num = num*10 + s[pos] - '0';
            }else{
                word += s[pos];
            }
        }
        
        return word;
    }
    
    // Stack Approach
    string soln_2(string s){
        stack<string> stk;
        int cur_num = 0;
        string cur_string = "";
        
        for(auto x:s){
            if(x == '['){
                stk.push(cur_string);
                stk.push(to_string(cur_num));
                cur_num = 0;
                cur_string = "";
            }else if(x == ']'){
                string num = stk.top();
                stk.pop();
                string prev_string = stk.top();
                stk.pop();
                
                int k = stoi(num);
                                
                cur_string = prev_string + nTimesString(cur_string,k);
            }else if( isdigit(x) ){
                cur_num = cur_num*10 + x - '0';
            }else{
                cur_string += x;
            }    
        }
        
       
        return cur_string;
    }
    string nTimesString(string s, int n){
        string ans = "";
        for (int i = 0; i < n; i++) ans += s;
        return ans;
    }
};