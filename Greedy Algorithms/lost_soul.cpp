/*
https://codeforces.com/problemset/problem/2117/E
Lost Soul

You are given two integer arrays a and b, each of length n.
You may perform the following operation any number of times:

Choose an index i (1≤i≤n−1), and set ai:=bi+1, or set bi:=ai+1.
Before performing any operations, you are allowed to choose an index i (1≤i≤n) and remove both ai and bi from the arrays. This removal can be done at most once.

Let the number of matches between two arrays c and d of length m be the number of positions j (1≤j≤m) such that cj=dj.

Your task is to compute the maximum number of matches you can achieve

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

To find the optimum answer, try greedy approach: 
Pick the maximum index which can be equal: a[i] == b[i] for max i.

If no such index exists, then make equal: And largest index will be ans.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF (LLONG_MAX >> 1)

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
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++) 
        cin >> b[i];
    vector <bool> check(n+1, false);
    if (a[n-1] == b[n-1]) {
        cout << n << endl;
        return;
    }
    for (int i=n-2; i>=0; i--) {
        if (a[i] == b[i]) {
            cout << i + 1 << endl;
            return;
        }
        if ((a[i] == a[i+1]) || (b[i] == b[i+1])) {
            cout << i + 1 << endl;
            return;
        } 
        if (check[a[i]] || check[b[i]]) {
            cout << i + 1 << endl;
            return;
        }
        check[a[i+1]] = true;
        check[b[i+1]] = true;
    }
    cout << 0 << endl;
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

/*
a1 a2 a3 a4 a5 a6
b1 b2 b3 b4 b5 b6   

a1 b2 a3 b4 a5 b6
b1 a2 b3 a4 b5 a6 

remove a4, b4
a1 a2 a3 a5 a6
b1 b2 b3 b5 b6 

a1 b2 a3 b5 a6
b1 a2 b3 a5 b6


*/
