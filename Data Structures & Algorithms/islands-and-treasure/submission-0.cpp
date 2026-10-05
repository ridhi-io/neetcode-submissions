class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        // Put all treasures into the queue
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                
                if(grid[row][col] == 0) {
                    q.push({row, col});
                }
            }
        }

        // BFS
        while(!q.empty()) {
            
            auto [row, col] = q.front();
            q.pop();

            // Four directions
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};

            for(int i = 0; i < 4; i++) {
                
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                // Check boundaries
                if(newRow < 0 || newRow >= rows ||
                   newCol < 0 || newCol >= cols) {
                    continue;
                }

                // Don't go into walls
                if(grid[newRow][newCol] == -1) {
                    continue;
                }

                // Only visit unvisited empty cells
                if(grid[newRow][newCol] != INT_MAX) {
                    continue;
                }

                // Distance = current distance + 1
                grid[newRow][newCol] = grid[row][col] + 1;

                // Add this cell to queue
                q.push({newRow, newCol});
            }
        }
    }
};