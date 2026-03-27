#include <bits/stdc++.h>
#define int long long
#define INF 1e18 
using namespace std;

const int MAXV = 100010; // Soma maxima possivel de todos os valores
const int MAXN = 105;    // Quantidade maxima de itens

int dp[MAXV];
int peso[MAXN], valor[MAXN];
bool pegou[MAXN][MAXV]; // Matriz pra reconstruir as escolhas

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W; // W = Capacidade maxima da mochila
    cin >> N >> W;

    for(int i=0; i<N; i++){

        cin >> peso[i] >> valor[i];
    }

    // Inicializa tudo com infinito, MENOS o dp[0] que ja comeca com 0
    for(int i=1; i<MAXV; i++) dp[i] = INF;
    dp[0] = 0;

    for(int i=0; i<N; i++){

        for(int j=MAXV-1; j>=valor[i]; j--){

            // Se pegar o item diminui o peso necessario pra bater o valor 'j'
            if(dp[j - valor[i]] + peso[i] < dp[j]){

                dp[j] = dp[j - valor[i]] + peso[i];
                pegou[i][j] = true; // Marca a escolha
            }
        }
    }

    // --- RECONSTRUCAO ---
    // 1. Pega o maior valor cuja soma de pesos coube na mochila
    int melhor_valor = 0;
    for(int v=0; v<MAXV; v++){

        if(dp[v] <= W){

            melhor_valor = v;
        }
    }

    cout << melhor_valor << '\n';

    // 2. Caminho de volta
    vector<int> escolhidos;
    int atual_v = melhor_valor;

    for(int i = N-1; i >= 0; i--){

        // Se nesse estado eu decidi pegar o item
        if(pegou[i][atual_v]){

            escolhidos.push_back(i); // Salva o indice (0-indexed)
            atual_v -= valor[i];     // Remove o lucro gerado pra continuar voltando
        }
    }

    reverse(escolhidos.begin(), escolhidos.end());

    // Imprime os indices dos itens escolhidos (Se a questao for 1-indexed, so dar +1)
    for(int idx : escolhidos){

        cout << idx + 1 << " ";
    }
    cout << '\n';

    return 0;
}