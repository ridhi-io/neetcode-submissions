class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        // Find rotten and fresh fruits
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                
                if(grid[row][col] == 2) {
                    q.push({row, col});
                }
                
                if(grid[row][col] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        // BFS
        while(!q.empty() && fresh > 0) {
            
            int size = q.size();

            // Process one minute
            for(int i = 0; i < size; i++) {
                
                auto [row, col] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++) {
                    
                    int newRow = row + dr[j];
                    int newCol = col + dc[j];

                    // Check boundaries
                    if(newRow < 0 || newRow >= rows ||
                       newCol < 0 || newCol >= cols) {
                        continue;
                    }

                    // Only fresh fruit can become rotten
                    if(grid[newRow][newCol] != 1) {
                        continue;
                    }

                    // Make it rotten
                    grid[newRow][newCol] = 2;

                    // One less fresh fruit
                    fresh--;

                    // Add to queue
                    q.push({newRow, newCol});
                }
            }

            minutes++;
        }

        // If fresh fruits are still left
        if(fresh > 0) {
            return -1;
        }

        return minutes;
    }
};