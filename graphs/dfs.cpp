vector<vll> adj; // adjacency list
int n; // number of vertices
vector<bool> visited;

void dfs(ll v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}