class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int row, int col, int index) {

        // We found the entire word
        if(index == word.size()) {
            return true;
        }

        // Out of bounds
        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size()) {
            return false;
        }

        // Current cell doesn't match
        if(board[row][col] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore all 4 directions
        bool found =
            dfs(board, word, row + 1, col, index + 1) ||
            dfs(board, word, row - 1, col, index + 1) ||
            dfs(board, word, row, col + 1, index + 1) ||
            dfs(board, word, row, col - 1, index + 1);

        // UNDO
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int row = 0; row < board.size(); row++) {

            for(int col = 0; col < board[0].size(); col++) {

                if(dfs(board, word, row, col, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};