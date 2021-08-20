class Solution {
public:
    string reverseWords(string s) {
        return soln_1(s);
    }
    
    // Optimal Approach in place reversal
    // O(N) time and O(1) space
    string soln_1(string &s){
        size_t n = size(s);
        int i = 0, j = 0;

        while (i < n)
        {
            while (i < n && s[i] == ' ') i++;

            if (i < n && j > 0) s[j++] = ' ';        
           
            int start = j;
            while (i < n && s[i] != ' ') s[j++] = s[i++];
           
            reverse(s.begin() + start, s.begin() + j);
        }
        
        s.resize(j);
        reverse(s.begin(), s.end());
        return s;
    }
    
    // O(N) time and O(N) space approach
    string soln_2(string &s){
        int n = s.length();
        vector<string> words;
        
        int i=0;
        while(i < n){
            while(i < n && s[i] == ' ') i++;
            
            if(i == n) break;
            
            string temp = "";
            while(i < n && s[i] != ' ') temp += s[i++];
            words.push_back(temp);
        }
        
        string ans = "";
        reverse(begin(words),end(words));
        
        for(int i=0;i<words.size();i++){
            ans += words[i];
            if(i < words.size()-1){
                ans += ' ';
            }
        }
        
        return ans;
    }
    
    
};