class Solution {
public:

    vector<vector<string>> result;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check same column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for(int i = row - 1, j = col - 1;
            i >= 0 && j >= 0;
            i--, j--) {

            if(board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for(int i = row - 1, j = col + 1;
            i >= 0 && j < n;
            i--, j++) {

            if(board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backtrack(vector<string>& board, int row, int n) {

        // All queens placed
        if(row == n) {
            result.push_back(board);
            return;
        }

        // Try every column
        for(int col = 0; col < n; col++) {

            // Check if position is safe
            if(isSafe(board, row, col, n)) {

                // CHOOSE
                board[row][col] = 'Q';

                // EXPLORE
                backtrack(board, row + 1, n);

                // UNDO
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        backtrack(board, 0, n);

        return result;
    }
};