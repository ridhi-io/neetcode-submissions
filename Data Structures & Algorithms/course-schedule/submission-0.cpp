class Solution {
public:
    vector<vector<int>> adj;
    vector<int> state;

    bool dfs(int course) {
        // Currently exploring this course
        state[course] = 1;

        for (int next : adj[course]) {

            // Found a cycle
            if (state[next] == 1) {
                return false;
            }

            // Explore an unvisited course
            if (state[next] == 0) {
                if (!dfs(next)) {
                    return false;
                }
            }
        }

        // Finished exploring this course
        state[course] = 2;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        state.assign(numCourses, 0);

        // Build the graph
        for (auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
        }

        // Check every course
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i)) {
                    return false;
                }
            }
        }

        return true;
    }
};