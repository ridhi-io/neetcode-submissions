class Solution {
public:
    unordered_map<string, multiset<string>> adj;
    vector<string> route;

    void dfs(string airport) {
        while (!adj[airport].empty()) {
            string next = *adj[airport].begin();

            adj[airport].erase(adj[airport].begin());

            dfs(next);
        }

        route.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK");

        reverse(route.begin(), route.end());

        return route;
    }
};