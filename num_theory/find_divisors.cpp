vll find_divisors(ll n) {
    vll divisors;
    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            ll mirr = n / i;
            if (mirr != i) {
                divisors.push_back(mirr);
            }
        }
    }
    return divisors;
}
