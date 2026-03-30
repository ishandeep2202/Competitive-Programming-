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
    int n;
    cin >> n;
    vector <pair <int, int>> pts(n);
    set <pair <int, int>> st;
    for (int i=0; i<n; i++) {
        cin >> pts[i].first >> pts[i].second;
        st.insert(pts[i]);
    }
    map <pair <int, int>, pair <int, int>> ans;
    queue <pair <int, int>> qu;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i=0; i<n; i++) {
        int x = pts[i].first, y = pts[i].second;
        for (int j=0; j<4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (st.find({nx, ny}) == st.end()) {
                qu.push({x, y});
                ans[{x, y}] = {nx, ny};
            }
        }
    }
    while (!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (st.find({nx, ny}) == st.end()) continue;
            if (ans.find({nx, ny}) != ans.end()) continue;
            ans[{nx, ny}] = ans[{x, y}];
            qu.push({nx, ny});
        }
    }
    for (int i=0; i<n; i++) {
        int x = pts[i].first, y = pts[i].second;
        pair <int, int> pt = ans[{x, y}];
        cout << pt.first << " " << pt.second << endl;
    }
}
