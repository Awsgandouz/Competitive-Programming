vector<long long> fact(long long n) {
    vector<long long> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

// for counting each prime in the decomposition we can use a map

map<int ,int> fact(long long n) {
    map<int ,int> factorization;
    while (n % 2 == 0) {
        factorization[2]++;
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n > 1)
        factorization[n]++;
    return factorization;
}
