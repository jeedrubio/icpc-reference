vll prime_factors(ll n) {
    vll res;
    for (auto p : primes) {
        while (n % p == 0) {
            n /= p;
            res.push_back(p);
        }
    }
    if (n > 1) {
        res.push_back(n);
    }
    return res;
}