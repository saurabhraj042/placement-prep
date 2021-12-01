// https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int x) {
        int r = size(m);
        int c = size(m[0]);
        
        int row = 0;
        int col = c - 1;
        
        while(row < r && col >= 0){
            int val = m[row][col];
            
            if(val == x) return true;
            
            if(val > x){
                col--;
            } else {
                row++;
            }
        }
        
        return false;
    }
};

/*
Suppose we want to search for 12 in the above matrix. compare 12 with the top-right element nums[0][4] = 15. Since 12 < 15, 12 cannot appear in the column of 15 since all elements in that column are greater than or equal to 15. Now we reduce the search space by one column (the last column).

We further compare 12 with the top-right element of the remaining matrix, which is nums[0][3] = 11. Since 12 > 11, 12 cannot appear in the row of 11 since all elements in this row are less than or equal to 11 (the last column has been discarded). Now we reduce the search space by one row (the first row).

We move on to compare 12 with the top-right element of the remaining matrix, which is nums[1][3] = 12. Since it is equal to 12, we return true.
*/