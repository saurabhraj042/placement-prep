//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = size(grid);
        int n = m ? size(grid[0]) : 0;
        int islands = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    erase(grid,i,j);
                }
            }
        }
        
        return islands;
    }
    
    void erase(vector<vector<char>>& grid,int i,int j){
        int m = size(grid);
        int n = size(grid[0]);
         if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        erase(grid, i - 1, j);
        erase(grid, i + 1, j);
        erase(grid, i, j - 1);
        erase(grid, i, j + 1);
    }
};