/*
https://codeforces.com/problemset/problem/330/B
Road Construction


Here we don't want to create roads which are already present here
Given constraints: 0 <= m <= n/2
So there will be atleast 1 vertex which which is not part of m edges in the given input. So we need to connect vertices to that vertex. 
So answer is always n-1 and connect vertices from that point to all. This will result in connection to all vertices where distance is almost 2.
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
    vector <bool> p(1010, false);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        p[a] = p[b] = true;
    } 
    int v = -1;
    for (int i=1; i<=n; i++) {
        if (!p[i]) {
            v = i;
            break;
        }
    }
    cout << n-1 << endl;
    for (int i=1; i<=n; i++) {
        if (i == v)
            continue;
        cout << v << " " << i << endl;
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
