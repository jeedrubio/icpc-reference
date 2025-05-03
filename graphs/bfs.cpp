vector<vll> adj; // adjacency list
ll n; // number of nodes
ll s; // source vertex

queue<ll> q;
vector<bool> used(n);
vll d(n); // path lengths from s to i
vll p(n); // parents

void bfs() {
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}

vll get_path(ll u) {
    if (!used[u]) {
        return {};
    }
    vll path;
    for (ll v = u; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}