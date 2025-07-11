/*
https://codeforces.com/problemset/problem/1166/C
A Tale of Two Lands

Here the sign will not affect the solution - proved mathematically 
Sort the array 
For ith element find the largest element which satisfies this |y-x| <= x -> x <= y <= 2x
All elements less than this will also satisfy (try j-1 with same i and it shifts everything by 1 except i but not true for j+1)
*/



#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;

void debugMode() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

bool possible(int mid, int n, int tar, vector <int> &a) {
    if (a[mid] >= tar && a[mid] <= 2 * tar) return true;
    else return false;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    vector <int> a(n), temp(n-1, 0);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] < 0) a[i] = -a[i];
    }
    sort(a.begin(), a.end());
    for (int i=0; i<n-1; i++) {
        if (a[i] == 0) 
            continue;
        int tar = a[i], cnt = 0;
        int low = i, high = n-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(mid, n, tar, a)) {
                cnt = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }   
        temp[i] = cnt - i;
        ans += (cnt - i);
    }
    cout << ans << endl;
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
