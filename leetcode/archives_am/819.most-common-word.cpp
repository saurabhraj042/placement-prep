// https://leetcode.com/problems/most-common-word/
class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        for (auto & c: p) c = isalpha(c) ? tolower(c) : ' ';
        
        unordered_map <string, int> words;
        unordered_set<string> ban_w(banned.begin(), banned.end());
        
        int i = 0;
        int n = p.length();
        
        cout << p;
        
        while(i < n){
            string word = "";
            
            while(p[i] == ' ' && i < n) i++;
            
            while(p[i] != ' ' && i < n){
                word += p[i];
                i++;
            }
            
            // It's important to check if our word has null value or not.
            // "a." => "a " => in this test case the map looks like this,
            // a : 1
            // "" : 1   , so we need to avoid putting null values in map.
            if(ban_w.find(word) == ban_w.end() && word != "")
                words[word]++;
        }
        
    
        
        string ans = "";
        int fq = 0;
        
        for(auto word : words){
            if(word.second > fq){
                fq = word.second;
                ans = word.first;
            }    
        }
        
        return ans;
    }
};

/*

The description doesn't clearify the case like "word,word,word".
And it doesn't have this kind of corner cases at first.
The test cases and OJ may not be perfect on this problem.

Anyway I didn't bother thinking this issue.
In my opinion, the problem demands to extract words with only letters.
All I did is just extract words with only letters.

4 steps:

remove all punctuations
change to lowercase
words count for each word not in banned set
return the most common word

*/