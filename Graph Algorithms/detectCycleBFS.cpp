bool detectCycleBFS(int start, vector <vector <int>> &adj, vector <int> &vis) {
    vis[start] = 1;
    queue <pair <int, int>> q; // node and it's parent in that cycle
    q.push({start, -1});
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode: adj[node]) {
            if (!vis[adjacentNode]) {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if (parent != adjacentNode) { // this means node already visited
                return true;
            }
        }
    }
    return false;
}
