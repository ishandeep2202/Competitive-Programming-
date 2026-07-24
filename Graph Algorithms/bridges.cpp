class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <vector <int>> adj(n);
        for (auto& e: connections) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector <vector <int>> ans;
        vector <int> in_time(n, 0), low_time(n, 0), vis(n, 0);
        int TIME = 0;
        auto dfs = [&](int curr, int par, auto&& dfs) -> void {
            vis[curr] = 1;
            in_time[curr] = low_time[curr] = TIME++;
            for (auto& node: adj[curr]) {
                if (!vis[node]) {
                    dfs(node, curr, dfs);
                    low_time[curr] = min(low_time[curr], low_time[node]);
                    if (low_time[node] > in_time[curr]) {
                        ans.push_back({node, curr});
                    } 
                }
                else if (node != par) {
                    low_time[curr] = min(low_time[curr], in_time[node]);
                }
            }
        };
        dfs(0, -1, dfs);
        return ans;
    }
};
