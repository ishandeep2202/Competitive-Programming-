/*
You are given two arrays A and B of length n

For every index in the array, find the length 
of the smallest subarray starting from index i
such that there exist at least B[i] elements 
with a value greater than or equal to A[i] in 
the subarray. If no such subarray exists, then print -1 

*/

#include <bits/stdc++.h>
using namespace std;

class FenwikTree {
public:
    int n;
    vector <int> bit;
    FenwikTree(int n) {
        this->n = n;
        bit.resize(n+1, 0);
    }
    void update(int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }
    int query(int i) {
        int ans = 0;
        while (i > 0) {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }
    int find(int sum) {
        int ind = 0, prev = 0;
        int mx = log2(n);
        for (int i=mx; i>=0; i--) {
            if (ind + (1 << i) <= n && bit[ind + (1 << i)] + prev < sum) {
                ind += (1 << i);
                prev += bit[ind];
            }
        }
        return ind + 1;
    }
};

struct ele {
    int i, a, b;
};

int main() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    vector <ele> v(n);
    for (int i=0; i<n; i++) {
        v[i].i = i+1;
        v[i].a = a[i];
        v[i].b = b[i];
    }
    sort(v.begin(), v.end(), [](auto& e1, auto& e2) {
        if (e1.a != e2.a) {
            return e1.a < e2.a;
        }
        return e1.i < e2.i;
    });
    vector <int> ans(n+1, 0);
    FenwikTree ft(n);
    for (int i=n-1; i>=0; i--) {
        ft.update(v[i].i, 1);
        int preS = ft.query(v[i].i-1);
        int curr = ft.find(v[i].b + preS);
        if (curr == n+1) {
            ans[v[i].i] = -1;
        }
        else ans[v[i].i] = curr - v[i].i + 1;
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " "; 
    }
    cout << endl;
}
