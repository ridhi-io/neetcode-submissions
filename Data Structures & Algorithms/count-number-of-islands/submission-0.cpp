class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Boundary check
        if(row < 0 || row >= rows ||
           col < 0 || col >= cols) {
            return;
        }

        // Water hai ya already visited hai
        if(grid[row][col] == '0') {
            return;
        }

        // Land ko visited mark karo
        grid[row][col] = '0';

        // 4 directions mein explore karo
        dfs(grid, row + 1, col); // Down
        dfs(grid, row - 1, col); // Up
        dfs(grid, row, col + 1); // Right
        dfs(grid, row, col - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {

                if(grid[row][col] == '1') {
                    count++;
                    dfs(grid, row, col);
                }
            }
        }

        return count;
    }
};