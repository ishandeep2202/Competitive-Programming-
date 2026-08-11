#include <bits/stdc++.h>
using namespace std;
#define int long long

#define INF (LLONG_MAX >> 1)

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, int>>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int src, dest;
    cin >> src >> dest;
    src--; dest--;
    vector <vector <pair <int, int>>> adj2(n);
    vector <int> vis(n, 0), min_cost(n, INF);
    priority_queue <tuple <int, int, int>, vector <tuple <int, int, int>>, greater <>> pq;
    min_cost[src] = 0;
    pq.push({0, src, -1});
    while (!pq.empty()) {
        int d = get<0>(pq.top()), u = get<1>(pq.top()), p = get<2>(pq.top());
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        if (p != -1) {
            adj2[p].push_back({u, d});
            adj2[u].push_back({p, d});
        }
        for (auto& [v, w]: adj[u]) {
            if (!vis[v] && min_cost[v] > w) {
                min_cost[v] = w;
                pq.push({w, v, u});
            }
        }
    }
    vector <int> max_cost(n, -INF);
    max_cost[src] = 0;
    auto dfs = [&](int curr, int par, int cost, auto&& dfs) -> void {
        if (par != -1) {
            max_cost[curr] = max(max_cost[par], cost);
        }
        for (auto& [node, w]: adj2[curr]) {
            if (node != par) {
                dfs(node, curr, w, dfs);
            }
        }
    };
    dfs(src, -1, 0, dfs);
    int ans = (max_cost[dest] == -INF ? -1 : max_cost[dest]);
    cout << ans << endl;
}
