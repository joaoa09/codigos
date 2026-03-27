#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 200005;

struct Tarefa {
    int ini, fim, lucro, id;
};

// Ordenacao por TEMPO DE FIM e obrigatoria para a DP funcionar
bool comp(Tarefa a, Tarefa b) {
    if(a.fim != b.fim) return a.fim < b.fim;
    return a.ini < b.ini;
}

Tarefa t[MAXN];
int dp[MAXN];
int tempos_fim[MAXN];
int escolheu[MAXN]; // 1 se pegou a tarefa 'i', 0 se ignorou

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> t[i].ini >> t[i].fim >> t[i].lucro;
        t[i].id = i;
    }

    sort(t + 1, t + N + 1, comp);

    // Array paralelo para busca binaria (lower/upper bound)
    for(int i = 1; i <= N; i++) tempos_fim[i] = t[i].fim;

    dp[0] = 0;

    for(int i = 1; i <= N; i++){
        
        /* --- GUIA DE COMPATIBILIDADE ---
           Se Fim=10 e Prox_Inicio=10 PODE: usar upper_bound(..., t[i].ini)
           Se Fim=10 e Prox_Inicio=10 NAO PODE: usar lower_bound(..., t[i].ini)
        */
        int j = upper_bound(tempos_fim + 1, tempos_fim + i, t[i].ini) - tempos_fim - 1;

        // Decisao: Lucro de FAZER a tarefa atual + lucro da melhor anterior compativel
        if(t[i].lucro + dp[j] > dp[i-1]){
            dp[i] = t[i].lucro + dp[j];
            escolheu[i] = j; // Guarda de qual estado 'j' a gente veio ao aceitar 'i'
        } else {
            dp[i] = dp[i-1];
            escolheu[i] = -1; // -1 indica que ignoramos a tarefa 'i'
        }
    }

    cout << dp[N] << '\n';

    // --- RECONSTRUCAO ---
    vector<int> res;
    int atual = N;
    while(atual > 0){
        if(escolheu[atual] != -1){
            res.push_back(t[atual].id);
            atual = escolheu[atual]; // Pula direto para a tarefa anterior compativel
        } else {
            atual--; // Apenas volta para a tarefa imediatamente anterior
        }
    }

    reverse(res.begin(), res.end());
    for(int x : res) cout << x << " ";
    cout << '\n';

    /* --- DICAS EXTRAS ---
       1. Se quiser APENAS o maior numero de tarefas (sem lucro): setar lucro = 1 para todos.
       2. Se os tempos forem 10^18: o codigo ja funciona (long long + lower_bound).
       3. Se pedir a menor "folga" entre tarefas: a logica muda para minimizar (dp[j] + gap).
    */

    return 0;
}