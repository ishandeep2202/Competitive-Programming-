/*
https://codeforces.com/contest/601/problem/A
The Two Routes

BFS (Breadth Search First) 
It is used to find the distance between 2 vertices - shortest distance
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rail(n+10);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        rail[u].push_back(v);
        rail[v].push_back(u);
    }
    vector <vector <int>> road(n+10);
    for (int i=1; i<=n; i++) {
        vector <int> curr = rail[i];
        for (int v=1; v<=n; v++) {
            if (count(curr.begin(), curr.end(), v) == 0) 
                road[i].push_back(v);
        }
    } 
    queue<int> q1;
    vector <int> dist1(n+10, -1);
    dist1[1] = 0;
    q1.push(1);
    while (!q1.empty()) {
        int v = q1.front();
        q1.pop();
        for (int u : rail[v]) {
            if (dist1[u] == -1) {
                dist1[u] = dist1[v] + 1;
                q1.push(u);
            }
        }
    }
    queue <int> q2; 
    vector <int> dist2(n+10, -1);
    dist2[1] = 0;
    q2.push(1);
    while (!q2.empty()) {
        int v = q2.front();
        q2.pop();
        for (int u: road[v]) {
            if (dist2[u] == -1) {
                dist2[u] = dist2[v] + 1;
                q2.push(u);
            }
        }
    }
    int d1 = dist1[n], d2 = dist2[n];
    if (d1 == -1 || d2 == -1) 
        cout << -1 << endl;
    else cout << max(d1, d2) << endl;
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
