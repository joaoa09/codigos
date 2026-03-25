#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // --- 1. TODOS OS SUBCONJUNTOS (BITMASK) ---
    // Complexidade: O(2^N * N)
    for (int mask = 0; mask < (1 << n); mask++) {
        int soma_atual = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                soma_atual += v[i];
            }
        }
        // Use a soma_atual aqui
    }

    // --- 2. TODAS AS PERMUTACOES ---
    // Complexidade: O(N! * N)
    sort(v.begin(), v.end()); // OBRIGATORIO estar ordenado para next_permutation
    do {
        // v agora contem uma permutacao unica. Processe-a aqui.
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}