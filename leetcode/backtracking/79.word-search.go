package backtracking
// https://leetcode.com/problems/word-search/
func exist(board [][]byte, word string) bool {
    m := len(board)
    n := len(board[0])
    
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == word[0] && dfs(board, i, j, 0, word) {
                return true;
            }
        }
    }
    
    return false
}

func dfs(board [][]byte, i, j, count int, word string) bool { 
    if count == len(word) {
        return true
    }
    
    if i < 0 || i >= len(board) || j < 0 || j >= len(board[0]) || board[i][j] != word[count] {
        return false
    }
    
    temp := board[i][j]
    board[i][j] = '*'
    
    found := dfs(board, i+1, j, count + 1, word) || dfs(board, i, j+1, count + 1, word) || dfs(board, i-1, j, count + 1, word) || dfs(board, i, j-1, count + 1, word)
    
    
    board[i][j] = temp
    
    return found
}