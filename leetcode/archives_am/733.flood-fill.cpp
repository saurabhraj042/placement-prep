// https://leetcode.com/problems/flood-fill/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor){
        int m = image.size(), n = image[0].size();
        if (r >= m || r < 0 || c >= n || c < 0) return;
        if (image[r][c] != oldColor || image[r][c] == newColor) return;
        image[r][c] = newColor;
        dfs(image, r+1, c, oldColor, newColor);
        dfs(image, r-1, c, oldColor, newColor);
        dfs(image, r, c+1, oldColor, newColor);
        dfs(image, r, c-1, oldColor, newColor);
    }
};