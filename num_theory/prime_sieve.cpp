vll prime_sieve(ll n) {
    vector<bool> sieve(n + 1, true);
    vll res;
    sieve[0] = sieve[1] = false;
    for (ll i = 2; i*i <= n; i++) {
        if (sieve[i]) {
            res.push_back(i);
            for (ll j = i*i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
    return res;
}