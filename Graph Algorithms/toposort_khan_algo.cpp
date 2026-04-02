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
    vector <int> indegree(n, 0);
    for (int i=0; i<n; i++) {
        for (auto &j: adj[i]) 
            indegree[j]++;
    }
    queue <int> qu;
    for (int i=0; i<n; i++)
        if (indegree[i] == 0) qu.push(i);
    vector <int> topo;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        topo.push_back(u);
        for (auto &v: adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) qu.push(v);
        }
    }
    printV(topo);
}
