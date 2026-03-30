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

class UnionFind {
    private: vector <int> parent, rank;
    public: 
    UnionFind(int n) {
        rank.assign(n, 0); parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0LL);
    }
    int findSet(int i) {
        return (parent[i] == i) ? i : parent[i] = findSet(parent[i]);
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) 
                parent[y] = x;
            else {
                parent[x] = y;
                if (rank[x] == rank[y]) 
                    rank[y]++;
            }
        }
    }
};

int32_t main() {
    // debugMode();
    int n, m;
    cin >> n >> m;
    UnionFind DSU(n);
    while (m--) {
        string type;
        int a, b;
        cin >> type >> a >> b;
        a--; b--;
        if (type == "union") {
            DSU.unionSet(a, b);
        }
        else {
            cout << (DSU.isSameSet(a, b) ? "YES" : "NO") << endl;
        }
    }
}
