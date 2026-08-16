#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF (INT_MAX >> 1)

const int M = 20;

void solve() {
    int n;
    cin >> n;
    vector <vector <pair <int, int>>> adj(n);   
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector <int> dept(n, 0);
    vector <vector <pair <int, int>>> Par(n, vector <pair <int, int>> (M));
    vector <vector <pair <int, int>>> Par2(n, vector <pair <int, int>> (M));
    auto dfs = [&](int curr, int par, int wt, auto&& dfs) -> void {
        if (curr == par) {
            Par[curr][0] = {par, -INF};
            Par2[curr][0] = {par, INF};
        }
        else {
            Par[curr][0] = {par, wt};
            Par2[curr][0] = {par, wt};
        }
        for (int i=1; i<M; i++) {
            int a = Par[Par[curr][i-1].first][i-1].first;
            int b = max(Par[Par[curr][i-1].first][i-1].second, Par[curr][i-1].second);
            int c = Par2[Par2[curr][i-1].first][i-1].first;
            int d = min(Par2[Par2[curr][i-1].first][i-1].second, Par2[curr][i-1].second);
            Par[curr][i] = {a, b};
            Par2[curr][i] = {c, d};
        }
        for (auto& [node, w]: adj[curr]) {
            if (node != par) {
                dept[node] = dept[curr] + 1;
                dfs(node, curr, w, dfs);
            }
        }
    };  
    dfs(0, 0, -INF, dfs);
    auto query = [&](int u, int v) -> pair <int, int> {
        if (dept[u] > dept[v]) {
            swap(u, v);
        }
        int diff = dept[v] - dept[u], ans = -INF, ans2 = INF;
        for (int i=M-1; i>=0; i--) {
            if (diff & (1LL << i)) {
                ans = max(ans, Par[v][i].second);
                ans2 = min(ans2, Par2[v][i].second);
                v = Par[v][i].first;
            }
        }
        for (int i=M-1; i>=0; i--) {
            if (Par[u][i].first != Par[v][i].first) {
                ans = max(ans, Par[u][i].second);
                ans = max(ans, Par[v][i].second);
                ans2 = min(ans2, Par2[u][i].second);
                ans2 = min(ans2, Par2[v][i].second);
                u = Par[u][i].first;
                v = Par[v][i].first;
            }
        }
        if (u == v) {
            return {ans, ans2};
        }
        ans = max(ans, Par[u][0].second);
        ans = max(ans, Par[v][0].second);
        ans2 = min(ans2, Par2[u][0].second);
        ans2 = min(ans2, Par2[v][0].second);
        return {ans, ans2};
    };

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        pair <int, int> ans = query(u, v);
        cout << ans.second << " " << ans.first << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i=1; i<=tt; i++) {
        cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
}
