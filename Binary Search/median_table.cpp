/*
https://cses.fi/problemset/result/13116748/
Multiplication Table

Aim is to find the middle element of this (n * n) where n is odd.

Since array is sorted - Binary search 
1 2 3 4 5          = 1(1 2 3 4 5)
2 4 6 8 10         = 2(1 2 3 4 5)
3 6 9 12 15        = 3(1 2 3 4 5)
4 8 12 16	20       = 4(1 2 3 4 5)
5 10	15 20 25     = 5(1 2 3 4 5)

So assume mid to be median and calculate the count of elements less than mid element.
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
 
bool possible(int mid, int n) {
    int cnt = 0;
 
    for (int i=0; i<n; i++) 
        cnt += min(mid / (i+1), n);
    
    if (cnt >= (n*n + 1) / 2) 
        return true;
    else return false;
}
 
void solve() {
    int n, ans = -1;
    cin >> n;
 
    int low = 0, high = n*n;
    while (low <= high) {
        int mid = (low + high) / 2;
 
        if (possible(mid, n)) {
            ans = mid;
            high = mid - 1;
        } 
 
        else low = mid + 1;
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
