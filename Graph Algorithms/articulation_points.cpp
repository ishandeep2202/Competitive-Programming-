class Solution {
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector <vector <int>> adj(V);
        for (auto& e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector <int> is_art(V, 0);
        vector <int> in_time(V, 0), low_time(V, 0), vis(V, 0);
        int TIME = 0;
        auto dfs = [&](int curr, int par, auto&& dfs) -> void {
            vis[curr] = 1;
            in_time[curr] = low_time[curr] = TIME++;
            int child = 0;
            for (auto& node: adj[curr]) {
                if (!vis[node]) {
                    child++;
                    dfs(node, curr, dfs);
                    low_time[curr] = min(low_time[curr], low_time[node]);
                    if (low_time[node] >= in_time[curr] && par != -1) {
                        is_art[curr] = 1;
                    }
                }
                else if (node != par) {
                    low_time[curr] = min(low_time[curr], in_time[node]);
                }
            }
            if (par == -1 && child > 1) {
                is_art[curr] = 1;
            }
        };
        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                dfs(i, -1, dfs);
            }
        }
        vector <int> ans;
        for (int i=0; i<V; i++) {
            if (is_art[i]) {
                ans.push_back(i);
            }
        }
        if (ans.empty()) {
            ans.push_back(-1);
        }
        return ans;
    }
};
