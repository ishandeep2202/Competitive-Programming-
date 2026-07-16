#include <bits/stdc++.h>

int main() {

    int n, q;
    std::cin >> n >> q;
    
    std::vector <std::vector <int>> adj(n);
    for (int i=1; i<n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int M = 20;
    std::vector <int> dept(n, 0);
    std::vector <std::vector <int>> Par(n, std::vector <int> (M, -1));  
    auto dfs = [&](int curr, int par, auto&& dfs) -> void {
        Par[curr][0] = par;
        for (int j=1; j<M; j++) {
            Par[curr][j] = Par[Par[curr][j-1]][j-1];
        }
        for (auto& node: adj[curr]) {
            if (node != par) {
                dept[node] = dept[curr] + 1;
                dfs(node, curr, dfs);
            }
        }
    };
    dfs(0, 0, dfs);

    auto KPar = [&](int u, int k) {
        for (int j=0; j<M; j++) {
            if ((k >> j) & 1) {
                u = Par[u][j];
            }
        }
        return u;
    };


    auto lca = [&](int a, int b) {
        if (dept[a] > dept[b]) {
            std::swap(a, b);
        }
        b = KPar(b, dept[b] - dept[a]);

        for (int i=M-1; i>=0; i--) {
            int pa = Par[a][i];
            int pb = Par[b][i];
            if (pa != pb) {
                a = pa;
                b = pb;
            }
        }

        int lca = (a == b) ? a : Par[a][0];
        return lca;
    };

    while (q--) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;   

        int dis = dept[a] + dept[b] - 2 * dept[lca(a, b)];
        std::cout << dis << '\n';
    }
}
