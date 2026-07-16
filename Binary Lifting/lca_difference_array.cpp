#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector <vector <int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; 
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    const int M = 20;
    vector <int> dept(n, 0);
    vector <vector <int>> Par(n+1, vector <int> (M, -1));
    auto dfs = [&](int curr, int par, auto&& dfs) -> void {
        Par[curr][0] = par;
        for (int i=1; i<M; i++) {
            Par[curr][i] = Par[Par[curr][i-1]][i-1];
        }
        for (auto& node: adj[curr]) {
            if (node != par) {
                dept[node] = dept[curr] + 1;
                dfs(node, curr, dfs);
            }
        }
    };
    dfs(0, 0, dfs);

    auto Kpar = [&](int u, int k) {
        for (int i=M-1; i>=0; i--) {
            if ((k >> i) & 1) {
                u = Par[u][i];
            }
        }
        return u;
    };

    auto lca = [&](int u, int v) {
        if (dept[u] > dept[v]) {
            swap(u, v);
        }
        v = Kpar(v, dept[v] - dept[u]);
        for (int i=M-1; i>=0; i--) {
            int pu = Par[u][i];
            int pv = Par[v][i];

            if (pu != pv) {
                u = pu;
                v = pv;
            }
        }
        
        int lca = (u == v) ? u : Par[u][0];
        return lca;
    };

    vector <int> ans(n, 0);
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        ans[u]++;
        ans[v]++;
        ans[lca(u, v)]--;
        if (Par[lca(u, v)][0] != lca(u, v)) {
            ans[Par[lca(u, v)][0]]--;
        }
    }

    auto dfs2 = [&](int curr, int par, auto&& dfs2) -> void {
        for (auto& node: adj[curr]) {
            if (node != par) {
                dfs2(node, curr, dfs2);
                ans[curr] += ans[node];
            }
        }
    };
    dfs2(0, -1, dfs2);   
    
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
