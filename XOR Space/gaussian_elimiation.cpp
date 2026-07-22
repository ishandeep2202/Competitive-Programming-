/*
An array a consists of a1,a2,⋯,an. How many unique subsets of a sum to k? Print your answer in mod 109+7.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define INF (LLONG_MAX >> 1)

const int M = 1e9+7;

int mod_exp(int b, int e) {
    int res = 1;
    while (e > 0) {
        if (e & 1) {
            res = (res * b) % M;
        }
        b = (b * b) % M;
        e >>= 1;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int sz = 0;
    vector <int> basis(32, 0);
    for (int i=0; i<n; i++) {
        int mask;
        cin >> mask;
        for (int i=31; i>=0; i--) {
            if (((mask >> i) & 1) == 0) {
                continue;
            } 
            else if (!basis[i]) {
                basis[i] = mask;
                sz++;
                break;
            }
            mask = (mask ^ basis[i]);
        }
    }
    int b = 31, curr = 0;
    while (b >= 0 && ((k >> b) & 1) == 0) {
        b--;
    }
    if (!basis[b]) {
        cout << 0 << endl;
        return 0;
    }
    curr = basis[b];
    for (; b>=0; b--) {
        if (((curr >> b) & 1) == ((k >> b) & 1)) {
            continue;
        }
        if (!basis[b]) {
            cout << 0 << endl;
            return 0;
        }
        curr = (curr ^ basis[b]);
    }
    int ans = mod_exp(2, n-sz);
    cout << ans << endl;
}
