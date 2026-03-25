#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5005;

int arr[MAXN];
int dp[MAXN];  // dp[i] = melhor resposta (tamanho, soma, etc) que TERMINA obrigatoriamente em arr[i]
int pai[MAXN]; // Pra reconstruir o caminho

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){

        cin >> arr[i];
    }

    int melhor_resposta = 0;
    int melhor_fim = -1;

    for(int i = 0; i < N; i++){

        // ESTADO INICIAL:
        dp[i] = 1;      // Se for de TAMANHO. (Se for de SOMA MAXIMA, mude para dp[i] = arr[i];)
        pai[i] = -1;

        // Olha pra todos os caras que vieram ANTES do arr[i]
        for(int j = 0; j < i; j++){

            // =====================================================================
            // A MAGICA ACONTECE AQUI NO IF. AQUI VC COLOCA AS REGRAS DA QUESTAO:
            //
            // 1. LIS Padrao Estritamente Crescente: 
            //    if(arr[j] < arr[i] && dp[j] + 1 > dp[i])
            //
            // 2. Crescente, mas Diferenca entre vizinhos tem que ser <= K:
            //    if(arr[j] < arr[i] && (arr[i] - arr[j]) <= K && dp[j] + 1 > dp[i])
            //
            // 3. Crescente, mas Alternando Paridade (Par -> Impar -> Par):
            //    if(arr[j] < arr[i] && (arr[j] % 2 != arr[i] % 2) && dp[j] + 1 > dp[i])
            //
            // 4. Maior SOMA Crescente (Nao tamanho, mas a maior soma dos elementos):
            //    if(arr[j] < arr[i] && dp[j] + arr[i] > dp[i])  <-- Note o + arr[i] em vez de + 1
            // =====================================================================

            if(arr[j] < arr[i] && dp[j] + 1 > dp[i]){

                dp[i] = dp[j] + 1; // Se for de SOMA MAXIMA, mude para: dp[i] = dp[j] + arr[i];
                pai[i] = j;
            }
        }

        // Atualiza a resposta global se o arr[i] gerou um final melhor
        if(dp[i] > melhor_resposta){

            melhor_resposta = dp[i];
            melhor_fim = i;
        }
    }

    cout << melhor_resposta << '\n';

    // --- RECONSTRUCAO ---
    vector<int> sequencia;
    int atual = melhor_fim;

    while(atual != -1){

        sequencia.push_back(arr[atual]);
        atual = pai[atual];
    }

    reverse(sequencia.begin(), sequencia.end());

    for(int x : sequencia){

        cout << x << " ";
    }
    cout << '\n';

    return 0;
}