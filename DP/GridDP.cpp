#include <bits/stdc++.h>
#define int long long
#define INF 1e18 
using namespace std;

const int MAXN = 1005;

int grid[MAXN][MAXN];
int dp[MAXN][MAXN];

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> grid[i][j];
        }
    }

    // 1. CASOS BASE E BORDAS FALSAS
    // Preenchemos com -INF para que o max() nunca escolha sair do grid
    for(int i = 0; i <= N; i++) dp[i][0] = -INF;
    for(int j = 0; j <= M; j++) dp[0][j] = -INF;

    dp[1][1] = grid[1][1];

    // 2. TRANSICAO DA DP
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(i == 1 && j == 1) continue;

            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];

            /* --- GUIA DE MODIFICACOES RAPIDAS ---
               
               A) MENOR Custo (Min Path):
                  - Mude o -INF das bordas para INF positivo.
                  - Troque 'max' por 'min' na linha acima.
                  - Na reconstrucao, mude '>' para '<' no if.

               B) QUANTOS caminhos (Number of Paths):
                  - Preencha as bordas falsas com 0.
                  - A transicao vira: dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
                  - Nao soma o grid[i][j] (a menos que existam obstaculos).
            */
        }
    }

    cout << dp[N][M] << '\n';

    // 3. RECONSTRUCAO (Caminho reverso)
    string caminho = "";
    int i = N, j = M;

    while(i > 1 || j > 1){
        if(i > 1 && j > 1){
            if(dp[i-1][j] > dp[i][j-1]){ // Trocar para '<' se for Min Path
                caminho += 'D'; // Down (Cima para Baixo)
                i--;
            } 
            else {
                caminho += 'R'; // Right (Esquerda para Direita)
                j--;
            }
        } 
        else if(i > 1){
            caminho += 'D';
            i--;
        } 
        else {
            caminho += 'R';
            j--;
        }
    }

    reverse(caminho.begin(), caminho.end());
    cout << caminho << '\n';

    return 0;
}