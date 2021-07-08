// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
class Solution {
public:
    int numberOfSubstrings(string s) {
        return atmost(s,3) - atmost(s,2);
    }
    
    int atmost(string s,int k){
        int start = 0;
        int end = 0;
        int count = 0;
        
        unordered_map<char,int> mp;
        
        for(;end<s.length();end++){
            char x = s[end];
            
            mp[x]++;
            if(mp[x] == 1) k--;
            
            while(k < 0){
                char y = s[start];
                mp[y]--;
                if(mp[y]==0) k++;
                start++;
            }
            
            count += end - start + 1;
        }
        
        return count;
    }
};