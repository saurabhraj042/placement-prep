// https://leetcode.com/problems/find-all-anagrams-in-a-string/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        return soln_2(s,p);
    }
    
    // Sliding window + Sorting
    // TC : O( (n-m) * mlogm )
    vector<int> soln_1(string s,string p){
        size_t n = size(s);
        size_t m = size(p);
        vector<int> ans;
        
        sort(begin(p),end(p)); // O(mlogm)
        
        for(int i=0;i<=n-m;i++){
            string window = s.substr(i,m);
            sort(begin(window),end(window));
            if(window == p){
                ans.push_back(i);        
            }
        }
        
        return ans;
    }
    
    // Sliding window + Hash map
    // O(N)
    vector<int> soln_2(string s,string p){
        size_t n = size(s);
        size_t m = size(p);
        vector<int> ans;
        vector<int> pt(26,0);
        vector<int> og(26,0);
        
        if(m > n) return ans;
        
        for(int i=0;i<m;i++){
            pt[p[i] - 'a']++;
            og[s[i] - 'a']++;
        }
        
        if(pt == og) ans.push_back(0);
        
        for(int i=m;i<n;i++){
            og[s[i - m] - 'a']--;
            og[s[i] - 'a']++;
            if(pt == og) ans.push_back(i - m + 1);   
        }
        return ans;
    }
};