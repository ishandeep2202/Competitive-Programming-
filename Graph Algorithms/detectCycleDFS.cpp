bool dfs(int node, int parent, vector <int> &vis, vector <vector <int>> &adj) {
    vis[node] = 1;
    for (auto &adjacentNode: adj[node]) {
        if (!vis[adjacentNode]) {
            if (dfs(adjacentNode, node, vis, adj)) 
                return true; 
        }
        else if (adjacentNode != parent) 
            return true;
    }
    return false;
}

bool detectCycleDFS(int n, vector <vector <int>> &adj) {
    vector <int> vis(n, 0);
    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, vis, adj))
                return true;
        }
        return false;
    }
}
