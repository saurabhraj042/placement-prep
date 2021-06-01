// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/spiral-matrix-ii/description/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       
        int matrix[n][n];
        vector<vector<int>> ans(n);
        
        // Edge Case
        if (n == 0) {
            return ans;
        }
        
        // Normal Case
        int rowStart = 0;
        int rowEnd = n-1;
        int colStart = 0;
        int colEnd = n-1;
        int num = 1; //change
        
        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int i = colStart; i <= colEnd; i ++) {
                matrix[rowStart][i] = num ++; //change
            }
            rowStart ++;
            
            for (int i = rowStart; i <= rowEnd; i ++) {
                matrix[i][colEnd] = num ++; //change
            }
            colEnd --;
            
            for (int i = colEnd; i >= colStart; i --) {
                if (rowStart <= rowEnd)
                    matrix[rowEnd][i] = num ++; //change
            }
            rowEnd --;
            
            for (int i = rowEnd; i >= rowStart; i --) {
                if (colStart <= colEnd)
                    matrix[i][colStart] = num ++; //change
            }
            colStart ++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i].push_back(matrix[i][j]);
            }
        }
        
        return ans;


    }
};
// @lc code=end

