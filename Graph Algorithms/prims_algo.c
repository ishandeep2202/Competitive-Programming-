#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define INF (LLONG_MAX >> 1)

#define inpV(x) for(auto &i: x) {cin >> i;}
#define printV(x) for(auto i: x) {cout << i << " ";} cout << endl;

void debugMode() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int32_t main() {
    // debugMode();
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
    vector <tuple <int, int, int>> mst;
    vector <bool> vis(n, false);
    vector <int> min_cost(n, INF);
    priority_queue <tuple <int, int, int>, vector <tuple <int, int, int>>, greater <>> pq;
    min_cost[0] = 0;
    pq.push({0, 0, -1});
    while (!pq.empty()) {
        tuple <int, int, int> curr = pq.top();
        pq.pop();
        int cost = get <0> (curr), u = get <1> (curr), p = get <2> (curr);
        if (vis[u]) continue;
        vis[u] = true;
        if (p != -1) mst.push_back({p, u, cost});
        for (auto &node: adj[u]) {
            int v = node.first, w = node.second;
            if (!vis[v] && w < min_cost[v]) {
                min_cost[v] = w;
                pq.push({w, v, u});
            }
        }
    }
}
