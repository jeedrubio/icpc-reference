ll dp_f(ll n, vll const &ve) {
    vll dp(n);

    // base cases
    dp[0] = 0;
    dp[1] = abs(ve[1] - ve[0]);

    for (ll i = 2; i < n; i++) {
        // transitions
        dp[i] = min(
            dp[i - 1] + abs(ve[i] - ve[i - 1]),
            dp[i - 2] + abs(ve[i] - ve[i - 2])
        );
    }
    return dp[n - 1];
}
