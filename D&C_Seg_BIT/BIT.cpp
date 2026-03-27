#include <bits/stdc++.h>
#define int long long
using namespace std;

// ESTRUTURA DA BIT (Fenwick Tree)
struct BIT {
    int n;
    vector<int> tree;

    // Construtor: BIT sempre começa em 1. 
    // Se o N for 10^5, o vetor tera 10^5 + 1.
    BIT(int n) : n(n) {
        tree.assign(n + 1, 0);
    }

    // Adiciona 'valor' na posicao 'idx' -> O(log N)
    void update(int idx, int valor) {
        // Sobe na arvore somando o bit menos significativo (idx & -idx)
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] += valor;
        }
    }

    // Retorna a soma acumulada de [1...idx] -> O(log N)
    int query(int idx) {
        int soma = 0;
        // Desce na arvore subtraindo o bit menos significativo
        for (; idx > 0; idx -= idx & -idx) {
            soma += tree[idx];
        }
        return soma;
    }

    // Retorna a soma no intervalo [l...r] -> O(log N)
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }

    /* --- GUIA DE VARIACOES RAPIDAS ---
       1. XOR: Troque '+=' por '^' no update e '-' por '^' na query.
       2. RANGE UPDATE: Para somar V em [L, R] e ler o valor no ponto P:
          - update(L, V);
          - update(R + 1, -V);
          - O valor no ponto P sera: query(P);
       3. MAIOR VALOR (Prefix Max): So funciona se o valor so aumentar.
          Troque 'soma += tree[idx]' por 'res = max(res, tree[idx])'.
    */
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    BIT bit(n);

    // Exemplo de uso: lendo valores iniciais
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        bit.update(i, v);
    }

    // Processando queries
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) { // Update
            int id, val;
            cin >> id >> val;
            // Se for "substituir", mandamos a diferenca: bit.update(id, val - antigo)
            bit.update(id, val); 
        } else { // Query
            int l, r;
            cin >> l >> r;
            cout << bit.query(l, r) << '\n';
        }
    }

    return 0;
}