// https://leetcode.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return soln_2(s,t);
    }
   
    bool soln_2(string s,string t){
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1; // i+1 becoz initally we used 0 so it will cause problem when index is 0 
            m2[t[i]] = i + 1;
        }
        return true;
    }
    
    // Wrong Soluchan *-* find the edge cases
    bool soln_1(string s,string t){
        int n = s.length();
        int m = t.length();
        
        if(n != m) return false;
        unordered_map<char,char> mp;
        
        for(int i=0;i<n;i++){
            if(mp.find(s[i]) == mp.end() && mp.find(t[i]) == mp.end()){
               mp[s[i]] = t[i];
            }else if(mp[s[i]] != t[i]){
                return false;
            }
        }
        
        return true;
    }
};