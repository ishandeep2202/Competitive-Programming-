void dfs(int node, vector <vector <int>> &adj, vector <int> &vis, vector <int> &ls) {
    vis[node] = 1;
    ls.push_back(node);
    for (auto &it: adj[node]) {
        if (!vis[it]) 
            dfs(it, adj, vis, ls);
    }
}

vector <int> dfsOnGraph(int n, vector <vector <int>> adj) {
    vector <int> vis(n, 0), ls;
    int start = 0;
    dfs(start, adj, vis, ls);
    return ls;
}
