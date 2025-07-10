/*
https://codeforces.com/contest/505/problem/B
Mr. Kitayuta's Colorful Graph

To find that for a particular query how many different colour paths are possible from u to v vertex
Approach: 
Divide the graph in small graphs, 1 for each colour and then, check over the graph that if it is possible to reach to other given vertex in graph from u to v for each colour
and if possible increase the ans by 1 for that query...
*/


#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;

void debugMode() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 110, M = 110;
vector <int> gr[N][M];
vector <bool> check(N, false);

void dfs(int u, int c) {
    check[u] = true;
    for (int curr: gr[u][c]) {
        if (check[curr] == false) 
            dfs(curr, c);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        gr[u][c].push_back(v);
        gr[v][c].push_back(u);
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int ans = 0;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++)
                check[j] = false;
            dfs(u, i);
            if (check[v])
                ans++;
        }
        cout << ans << endl;
    }
}

int32_t main() {
    debugMode();
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}
