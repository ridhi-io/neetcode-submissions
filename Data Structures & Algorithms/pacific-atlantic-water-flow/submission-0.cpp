class Solution {
public:

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& ocean,
             int row,
             int col) {

        int rows = heights.size();
        int cols = heights[0].size();

        ocean[row][col] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int i = 0; i < 4; i++) {

            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if(newRow < 0 || newRow >= rows ||
               newCol < 0 || newCol >= cols) {
                continue;
            }

            if(ocean[newRow][newCol]) {
                continue;
            }

            if(heights[newRow][newCol] < heights[row][col]) {
                continue;
            }

            dfs(heights, ocean, newRow, newCol);
        }
    }


    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(
            rows, vector<bool>(cols, false)
        );

        vector<vector<bool>> atlantic(
            rows, vector<bool>(cols, false)
        );

        // Pacific: top row
        for(int col = 0; col < cols; col++) {
            dfs(heights, pacific, 0, col);
        }

        // Pacific: left column
        for(int row = 0; row < rows; row++) {
            dfs(heights, pacific, row, 0);
        }

        // Atlantic: bottom row
        for(int col = 0; col < cols; col++) {
            dfs(heights, atlantic, rows - 1, col);
        }

        // Atlantic: right column
        for(int row = 0; row < rows; row++) {
            dfs(heights, atlantic, row, cols - 1);
        }

        vector<vector<int>> result;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {

                if(pacific[row][col] &&
                   atlantic[row][col]) {

                    result.push_back({row, col});
                }
            }
        }

        return result;
    }
};