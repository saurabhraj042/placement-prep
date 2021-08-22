// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",        "wxyz"}, ans;        
    
    vector<string> letterCombinations(string s) {
        if(s.empty()) return ans;
        soln_1(s,0,"");
        return ans;
    }
    
    // Recursive Approach
    // O(4^N*N)
    
    void soln_1(string &s,int i,string comb){
        if(i == size(s)){
            ans.push_back(comb);
            return;
        } // end of the string
        
        int idx = s[i] - '2';
        
        for(auto &c:mappings[idx]){
            soln_1(s,i+1,comb+c);
        }
    }
};