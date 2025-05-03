ll n;
vector<bool> vis(n, false);
vll dp(n);
vll ve(n);

ll f_dp(ll i) {
    // base cases
    if (i < 0) return INF;
    if (i == 0) return 0;
    
    if (vis[i]) return dp[i];
    vis[i] = true;
    ll &ans = dp[i];

    // neutral element
    ans = INF;

    // transitions
    ans = min(ans,
        f_dp(i - 1) + abs(ve[i] - ve[i - 1])
    );

    ans = min(ans, 
        f_dp(i - 2) + abs(ve[i] - ve[i - 2])
    );

    return ans;
}