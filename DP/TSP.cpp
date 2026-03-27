#include <bits/stdc++.h>
#define int long long
#define INF 1e15
using namespace std;

int n;
int dist[21][21];
int dp[21][1 << 21]; 

/* VARIACAO 4 (ITENS/VITAMINAS):
   Se o problema exigir coletar itens (ex: A, B, C) alem de visitar cidades:
   1. Aumente a dimensao: dp[21][1 << 21][1 << NUM_ITENS]
   2. Crie um array: int item_na_cidade[21] (guarda a mask de itens de cada cidade)
   3. Na transicao: 
      int prox_m_itens = mask_itens | item_na_cidade[v];
      dp[v][next_mask][prox_m_itens] = min(..., dp[u][mask][mask_itens] + dist[u][v]);
*/

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(!(cin >> n)) return 0;

    // VARIACAO 5: Estradas Bloqueadas
    // Inicializamos tudo com INF. Se o input nao der o caminho, ele continua INF.
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) 
            dist[i][j] = (i == j ? 0 : INF);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];

    int max_mask = (1 << n);
    for(int i = 0; i < n; i++)
        for(int m = 0; m < max_mask; m++)
            dp[i][m] = INF;

    // VARIACAO 1: Comecar em QUALQUER cidade
    // Se puder começar em qualquer lugar, use o for. Se for fixo na 0, use dp[0][1<<0]=0.
    for(int i = 0; i < n; i++) dp[i][1 << i] = 0; 

    for(int mask = 1; mask < max_mask; mask++){
        for(int u = 0; u < n; u++){
            if(!(mask & (1 << u)) || dp[u][mask] >= INF) continue;

            for(int v = 0; v < n; v++){
                if(mask & (1 << v)) continue;
                
                int next_mask = mask | (1 << v);
                if(dp[v][next_mask] > dp[u][mask] + dist[u][v]){
                    dp[v][next_mask] = dp[u][mask] + dist[u][v];
                }
            }
        }
    }

    int full_mask = max_mask - 1;
    int ans = INF;

    // VARIACAO 3: Visitar exatamente K cidades
    // int K = ...; 
    // for(int m = 0; m < max_mask; m++) {
    //    if(__builtin_popcountll(m) == K) {
    //       for(int i=0; i<n; i++) ans = min(ans, dp[i][m]);
    //    }
    // }

    // VARIACAO 2: Caminho vs Ciclo
    // Para CICLO (Volta para a origem):
    for(int i = 0; i < n; i++) ans = min(ans, dp[i][full_mask] + dist[i][0]);
    
    // Para CAMINHO (Para na ultima cidade):
    // for(int i = 0; i < n; i++) ans = min(ans, dp[i][full_mask]);

    cout << (ans >= INF ? -1 : ans) << endl;

    return 0;
}