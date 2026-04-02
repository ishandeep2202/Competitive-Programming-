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
    vector <vector <int>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    vector <int> topo;
    vector <bool> vis(n, false);
    auto dfs = [&](int curr, auto &&dfs) -> void {
        vis[curr] = true;
        for (auto &node: adj[curr]) {
            if (!vis[node]) 
                dfs(node, dfs);
        }
        topo.push_back(curr);
    };
    for (int i=0; i<n; i++) {
        if (!vis[i]) 
            dfs(i, dfs);
    }
    reverse(topo.begin(), topo.end());
    printV(topo);
}
