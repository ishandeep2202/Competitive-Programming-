/*
  https://codeforces.com/contest/1520/problem/F1
  Guess the K-th Zero (Easy version)
*/

#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
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

vector <int> arr = {1,0,1,1,0,1};

// int query(int l, int r) {
//     cout << "? " << l << " " << r << endl;
//     int s;
//     cin >> s;
//     s = 0;
//     for (int i=l-1; i<=r-1; i++)
//         s += arr[i];
//     return s;
// }

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int s;
    cin >> s;
    return s;
}

void solve() {
    int n, t, k;
    cin >> n >> t >> k;
    int left = 1, right = n, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int zeros = mid - query(1, mid);
        if (zeros >= k) {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << "! " << ans << endl;
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
