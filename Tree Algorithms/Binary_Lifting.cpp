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
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int N = 20;
    vector <vector <pair <int, int>>> Par(n, vector <pair <int, int>> (N));
    vector <int> lvl(n, 0);
    auto dfs = [&](int curr, int par, int wt, auto &&dfs) -> void {
        Par[curr][0] = {par, wt};
        for (int i=1; i<N; i++) {
            int a = Par[Par[curr][i-1].first][i-1].first;
            int b = min(Par[Par[curr][i-1].first][i-1].second, Par[curr][i-1].second);
            Par[curr][i] = {a, b};
        }
        for (auto &node: adj[curr]) {
            if (node.first != par) {
                lvl[node.first] = lvl[curr] + 1;
                dfs(node.first, curr, node.second, dfs);
            }
        }
    };
    dfs(0, 0, INF, dfs);
    auto query = [&](int a, int b) -> int {
        int ans = INF;
        if (lvl[a] < lvl[b]) 
            swap(a, b);
        int dif = lvl[a] - lvl[b];
        for (int i=N-1; i>=0; i--) {
            if (dif & (1LL << i)) {
                ans = min(ans, Par[a][i].second);
                a = Par[a][i].first;
            }
        }
        if (a == b)
            return ans;
        for (int i=N-1; i>=0; i--) {
            if (Par[a][i].first != Par[b][i].first) {
                ans = min(ans, Par[a][i].second);
                ans = min(ans, Par[b][i].second);
                a = Par[a][i].first;
                b = Par[b][i].first;
            }
        }
        ans = min(ans, Par[a][0].second);
        ans = min(ans, Par[b][0].second);
        return ans;
    };
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << query(a, b) << endl;
    }
}
