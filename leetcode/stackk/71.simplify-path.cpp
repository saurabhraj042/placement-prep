// https://leetcode.com/problems/simplify-path/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int n = path.length();
        
        for(int i=0;i<n;i++){
            string c="";
            
            while(i<n && path[i]!='/') c+=path[i++];
            
            if(c=="" || c==".") continue;
            else if(c==".."){
                if(!s.empty()) s.pop();
            }else{
                s.push(c);
            }
        }
        
        string ans ="";
        
        while(!s.empty()){
            ans = '/' + s.top() + ans;
            s.pop();
        }
        
        if(ans=="") return "/";
        return ans;
    }
};