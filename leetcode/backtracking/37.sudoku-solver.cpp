class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        bool t = sol(board,0,0);
    }
private:
    
    bool sol( vector< vector<char> > &board,int row,int col ){
        if( row==9 ) return true;
        
        if( col==9 ){
            return sol(board,row+1,0);
        }
        
        if( board[row][col] != '.' ) return sol(board,row,col+1);
        
        
        for(char i='1';i<='9';i++){
            
            if( check( board,row,col,i) ){
                
                board[row][col] = i;
                
                if( sol(board,row,col+1) ){
                    return true;
                }
                
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    bool check( vector<vector<char> > &board,int row,int col,char num){
        
        for( int i=0;i<9;i++ ){
            if( board[row][i]==num ) return false;
        }
        
        for(int i=0;i<9;i++){
            if( board[i][col]==num ) return false;
        }
        
        int startRow = row - (row%3);
        int startCol = col - (col%3);
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if( board[ i+startRow ][ j+startCol ]==num ) return false;
            }
        }
        
        return true;
    }
};