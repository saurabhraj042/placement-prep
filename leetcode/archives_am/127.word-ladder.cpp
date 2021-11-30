// https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> nodes(wordList.begin(), wordList.end());
        queue<string> q;
        
        q.push(beginWord);
        int ladder = 1;
        
        while(!q.empty()){
            int n = q.size();
            for(int k = 0; k < n; k++){
                auto word = q.front();
                q.pop();

                if(word == endWord){
                    return ladder;
                }

                nodes.erase(word);

                for(int i = 0; i < word.size(); i++){
                    char c = word[i];

                    for(int j = 0; j < 26; j++){
                        word[i] = 'a' + j;

                        if(nodes.find(word) != nodes.end()){
                            q.push(word);
                        }
                    }

                    word[i] = c;
                }
            }
            
            ladder++;
        }
        
        return 0;
    }
};