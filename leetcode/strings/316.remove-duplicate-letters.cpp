class Solution {
public:
    string removeDuplicateLetters(string s) {
        return soln_1(s);
    }
    
    string soln_1(string &s){
        unordered_map<char,int> last_occ;
        unordered_set<char> visited;
        stack<char> stk;
        stk.push('!');
        
        for(int i=0;i<size(s);i++){
            last_occ[s[i]] = i;
        }
        
        for(int i=0;i<size(s);i++){
            char c = s[i];
            
            if(visited.find(c) != end(visited)) continue;
            
            while(c < stk.top() && last_occ[stk.top()] > i){
                visited.erase(stk.top());
                stk.pop();
            }
            
            visited.insert(c);
            stk.push(c);
        }
        
        string ans = "";
        while(size(stk) != 1){
            ans += stk.top();
            stk.pop();
        }
        
        reverse(begin(ans),end(ans));
        
        return ans;
    }
};