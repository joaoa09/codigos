#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1000005;
vector<bool> is_prime(MAXN, true);
vector<int> primes;

// 1. CRIVO: Acha todos os primos ate MAXN - O(N log log N)
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXN; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i < MAXN; i++) 
        if (is_prime[i]) primes.push_back(i);
}

// 2. FATORACAO: Decompõe N em fatores primos - O(sqrt(N))
vector<pair<int, int>> prime_factors(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) { cnt++; n /= i; }
            factors.push_back({i, cnt});
        }
    }
    if (n > 1) factors.push_back({n, 1});
    return factors;
}

// 3. DIVISORES: Acha todos os divisores de N ordenados - O(sqrt(N))
vector<int> get_divisors(int n) {
    vector<int> d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i*i != n) d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}