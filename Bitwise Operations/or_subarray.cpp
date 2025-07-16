/*
Define the coverage of a as the smallest positive integer k(1≤k≤n) such that for any two positive integers i and j (1≤i,j≤n−k+1), the following holds: ai|ai+1|…|ai+k−1=aj|aj+1|…|aj+k−1, 
where x|y denotes the bitwise OR of x and y. In other words, for every k consecutive elements, their bitwise OR should be the same. Note that the coverage of a is well-defined,
because for k=n the condition is always satisfied.

https://codeforces.com/group/NTAEHOlnST/contest/581265/problem/D
Simmy-Simmy-Sim!

Idea of binary search: 
for 8 elements if ans = 3 then consider:
a1 | a2 | a3 = a6 | a7 | a8 and a2 | a3 | a4 = a5 | a6 | a7
so combining both: a1 | a2 | a3 | a4 = a5 | a6 | a7 | a8 (valid for 4 also)
*/

#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define INF (LLONG_MAX >> 1)
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

bool possible(int k, int n, vector <int> &a) {
    int OR = 0, t = 25;
    vector <int> bit(t, -1); // stores the largest index which makes than bit on
    for (int i=0; i<k; i++) {
        OR |= a[i];
        for (int j=0; j<t; j++) 
            if (a[i] & (1LL << j)) 
                bit[j] = i;
    }
    for (int i=k; i<n; i++) {
        for (int j=0; j<t; j++) {
            if (a[i] & (1LL << j))
                bit[j] = i;
            if (OR & (1LL << j)) { // if bit is on in original segment then
                if (bit[j] <= i-k) // if it will not be on in any one of the last k elements then k is not possible 
                    return false;
            }
            else {                 // if k is off in the original result 
                if (bit[j] > i-k)  // then it should not be on in last k elements, otherwise false k 
                    return false;
            }
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    int left = 1, right = n, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (possible(mid, n, a)) {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans << endl;
}

int32_t main() {
    debugMode();
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
