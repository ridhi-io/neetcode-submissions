class Solution {
public:

    void dfs(vector<vector<char>>& board, int row, int col) {

        int rows = board.size();
        int cols = board[0].size();

        // Out of bounds
        if(row < 0 || row >= rows ||
           col < 0 || col >= cols) {
            return;
        }

        // Only process O
        if(board[row][col] != 'O') {
            return;
        }

        // Mark as safe
        board[row][col] = '#';

        // Go in 4 directions
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }

    void solve(vector<vector<char>>& board) {

        if(board.empty()) {
            return;
        }

        int rows = board.size();
        int cols = board[0].size();

        // First row
        for(int col = 0; col < cols; col++) {
            if(board[0][col] == 'O') {
                dfs(board, 0, col);
            }
        }

        // Last row
        for(int col = 0; col < cols; col++) {
            if(board[rows - 1][col] == 'O') {
                dfs(board, rows - 1, col);
            }
        }

        // First column
        for(int row = 0; row < rows; row++) {
            if(board[row][0] == 'O') {
                dfs(board, row, 0);
            }
        }

        // Last column
        for(int row = 0; row < rows; row++) {
            if(board[row][cols - 1] == 'O') {
                dfs(board, row, cols - 1);
            }
        }

        // Convert surrounded O -> X
        // Convert safe # -> O
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {

                if(board[row][col] == 'O') {
                    board[row][col] = 'X';
                }
                else if(board[row][col] == '#') {
                    board[row][col] = 'O';
                }
            }
        }
    }
};