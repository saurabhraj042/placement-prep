// https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {
        int map[128] = {0};
        
        for(auto x:t) map[x]++;
        
        size_t  size = s.size(),counter = t.size();
        int start = 0,end = 0,min_len = INT_MAX,head = 0;
        
        while(end < size){
            char cur_char = s[end];
            
            if(map[cur_char] > 0) counter--;
            
            map[cur_char]--;
            end++;
            
            while(counter == 0){
                
                if(end - start < min_len){
                    head = start;
                    min_len = end - start;
                }
                map[s[start]]++;
                
                if(map[s[start]] > 0) counter++;
                
                start++;
            }
        }
        
        return (min_len == INT_MAX) ? "" : s.substr(head,min_len);
    }
};