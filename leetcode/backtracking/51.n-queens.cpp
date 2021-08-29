class Solution {
public:
    vector<vector<string>> ret;
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        
        dfs(board,0);
        
        return ret;
    }

    bool is_valid(vector<string> &board, int row, int col){
        
        for(int i = row; i >= 0; --i)
            if(board[i][col] == 'Q') return false;
        
        for(int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if(board[i][j] == 'Q') return false;
        
        for(int i = row, j = col; i >= 0 && j < size(board); --i, ++j)
            if(board[i][j] == 'Q') return false;
        
        return true;
    }
    void dfs(vector<string> &board, int row){

        if(row == size(board)){
            ret.push_back(board);
            return;
        }

        for(int i=0; i<size(board); ++i){
            if(is_valid(board, row, i)){
                board[row][i] = 'Q';

                dfs(board,row+1);
                
                board[row][i] = '.';
            }
        }
    }
};