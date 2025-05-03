vll arr, segtree;

void build(ll node, ll l, ll r) {
    if (l == r) {
        segtree[node] = arr[l];
        return;
    }
        ll mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        segtree[node] = segtree[2 * node]
            + segtree[2 * node + 1];
}

void update(ll node, ll l, ll r, ll idx, ll val) {
    if (l == r) {
        arr[idx] = val;
        segtree[node] = val;
    } else {
        ll mid = (l + r) / 2;

        if (l <= idx && idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        segtree[node] = segtree[2 * node]
            + segtree[2 * node + 1];
    }
}

ll query(ll node, ll tl, ll tr, ll l, ll r) {
    if (r < tl || tr < l)
        return 0;

    if (l <= tl && tr <= r)
        return segtree[node];
    ll tm = (tl + tr) / 2;

    return query(2 * node, tl, tm, l, r)
           + query(2 * node + 1, tm + 1, tr, l, r);
}