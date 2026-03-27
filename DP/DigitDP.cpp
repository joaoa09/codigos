#include <bits/stdc++.h>
#define int long long
using namespace std;

// [posicao][ta_no_limite?][veio_so_de_zeros?][estado_customizado]
// estado_customizado pode ser a soma, o resto de um modulo, etc.
int dp[20][2][2][200];
string S;

int solve(int pos, bool tight, bool zero, int soma, int alvo) {
    // BASE: Se chegou no fim, verifica se a condicao foi atendida
    if (pos == S.size()) {
        return (soma == alvo); 
    }

    // MEMO: O estado agora inclui o 'zero' pra evitar contar zeros a esquerda
    if (dp[pos][tight][zero][soma] != -1) return dp[pos][tight][zero][soma];

    int res = 0;
    int limite = tight ? (S[pos] - '0') : 9;

    for (int d = 0; d <= limite; d++) {
        bool prox_tight = tight && (d == limite);
        
        // Se ainda for leading zero e o digito atual for 0, continua sendo leading zero
        bool prox_zero = zero && (d == 0);

        // --- REGRAS DA QUESTAO ---
        // Exemplo: soma dos digitos (so somamos se nao for zero a esquerda)
        int prox_soma = soma + (prox_zero ? 0 : d);
        
        res += solve(pos + 1, prox_tight, prox_zero, prox_soma, alvo);
    }

    return dp[pos][tight][zero][soma] = res;
}

int count_upto(int X, int alvo) {
    if (X < 0) return 0;
    S = to_string(X);
    memset(dp, -1, sizeof(dp));
    // Começa na pos 0, com tight=true (preso ao limite) e zero=true (so vieram zeros)
    return solve(0, true, true, 0, alvo);
}

// NO MAIN: cout << count_upto(R, alvo) - count_upto(L-1, alvo) << endl;

/* VARIACAO: Se o problema pedir "digitos adjacentes diferentes" (tipo 1212),
   voce adiciona um parametro 'ultimo_digito' no solve e na DP.
   Se zero for true, voce passa um valor 'fake' (tipo -1) pro proximo estado.
*/