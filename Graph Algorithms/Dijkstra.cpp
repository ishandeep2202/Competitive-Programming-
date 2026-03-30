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
    vector <int> dis(n, INF), Par(n, -1);
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <>> pq;
    dis[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int currD = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (currD > dis[u]) continue;
        for (auto &node: adj[u]) {
            int v = node.first;
            int w = node.second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
                Par[v] = u;
            }
        }
    }
    if (dis[n-1] == INF) {
        cout << -1 << endl;
        return 0;
    } 
    vector <int> ans;
    int curr = n-1;
    while (curr != 0) {
        ans.push_back(curr+1);
        curr = Par[curr];
    }
    ans.push_back(curr+1);
    reverse(ans.begin(), ans.end());
    printV(ans);
}
