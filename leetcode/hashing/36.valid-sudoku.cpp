// https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> row,col,sec;
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[i].size();j++){
                auto x = board[i][j];
                
                if(x != '.'){
                    
                    if(row[i].find(x) != row[i].end() || col[j].find(x) != col[j].end())
                        return 0;
                    
                    int s = (j/3) + 10 * (i/3);
                    
                    if(sec[s].find(x) != sec[s].end())
                        return 0;
                    
                    sec[s].insert(x);
                    row[i].insert(x);
                    col[j].insert(x);
                }
            }
        }
        
        return 1;
    }
};