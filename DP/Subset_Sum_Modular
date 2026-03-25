#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 100005;
const int MAXM = 1005; // Tamanho maximo do modulo M

int A[MAXN];
bool dp[MAXM];

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, alvo;
    cin >> N >> M >> alvo;

    for(int i = 0; i < N; i++){

        cin >> A[i];
        A[i] = (A[i] % M);
    }

    // Inicializa a DP
    for(int i = 0; i < M; i++){

        dp[i] = false;
    }

    // A sua transicao com o buffer
    for(int i = 0; i < N; i++){

        vector<int> ligar;

        // O proprio elemento sozinho ja garante o seu proprio resto
        ligar.push_back(A[i]);

        // Testa somar o item atual com todos os restos que ja formamos
        for(int j = 0; j < M; j++){

            if(dp[j]){

                ligar.push_back((j + A[i]) % M);
            }
        }

        // Descarrega os novos restos encontrados na DP principal
        for(int pos : ligar){

            dp[pos] = true;
        }
    }

    // Verifica se conseguimos bater o resto alvo
    if(dp[alvo]){

        cout << "YES\n";
    }
    else{

        cout << "NO\n";
    }

    return 0;
}