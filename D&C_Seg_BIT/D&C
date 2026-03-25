#include <bits/stdc++.h>
#define int long long
using namespace std;

// Exemplo de problema: Contar quantos pares (i, j) existem onde i < j e v[i] > v[j] (Inversoes)
int solve(int l, int r, vector<int>& v) {
    // 1. CASO BASE
    if (l >= r) return 0;

    int mid = l + (r - l) / 2;

    // 2. DIVIDIR: Resolve esquerda e direita
    int total_pares = solve(l, mid, v) + solve(mid + 1, r, v);

    // 3. CONQUISTAR (Processar o que cruza o meio):
    // Aqui voce conta quantos i (em [l, mid]) e j (em [mid+1, r]) batem a regra
    
    int j_ptr = mid + 1;
    for (int i = l; i <= mid; i++) {
        // Exemplo: enquanto o cara da direita for menor que o da esquerda
        while (j_ptr <= r && v[j_ptr] < v[i]) {
            j_ptr++;
        }
        // Todos os caras de mid+1 ate j_ptr-1 satisfazem a condicao para esse i
        total_pares += (j_ptr - (mid + 1));
    }

    // 4. MERGE (Opcional): Mantem o array ordenado para o pai usar Two Pointers
    inplace_merge(v.begin() + l, v.begin() + mid + 1, v.begin() + r + 1);

    return total_pares;
}

/* --- ABORDAGENS DIFERENTES PARA O MEIO ---
   A) TWO POINTERS: Se ao aumentar o 'i', o 'j' otimo tambem aumenta (O(N)).
   B) BUSCA BINARIA: Se para cada 'i', voce puder dar um lower_bound na direita (O(N log N)).
   C) BIT/SEGTREE: Se precisar contar algo mais complexo enquanto percorre.
*/

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        cout << solve(0, n - 1, v) << '\n';
    }

    return 0;
}