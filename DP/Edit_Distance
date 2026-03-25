#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 3005;
int dp[MAXN][MAXN];

// =====================================================================
// FUNCOES DE CUSTO (Altere aqui as regras do problema)
// Se o custo for fixo igual a 1, so deixar o 'return 1;'
// =====================================================================

int custo_apagar(char c){
    // Exemplo: se apagar a letra 'A' custar 5: if(c == 'A') return 5;
    return 1; 
}

int custo_inserir(char c){
    return 1;
}

int custo_substituir(char antiga, char nova){
    // Opcional: dependendo da questao, mudar 'a' pra 'b' pode ter um custo especifico
    return 1;
}

// =====================================================================

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int N = s1.size();
    int M = s2.size();

    // 1. CASOS BASE (Somando os custos cumulativos)
    dp[0][0] = 0;

    // Custo de apagar as 'i' primeiras letras de s1 (s2 vazia)
    for(int i = 1; i <= N; i++){
        
        dp[i][0] = dp[i-1][0] + custo_apagar(s1[i-1]);
    }

    // Custo de inserir as 'j' primeiras letras de s2 (s1 vazia)
    for(int j = 1; j <= M; j++){
        
        dp[0][j] = dp[0][j-1] + custo_inserir(s2[j-1]);
    }

    // 2. TRANSICAO DA DP
    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= M; j++){

            // Se as letras baterem, nao fazemos nenhuma operacao (custo 0)
            if(s1[i-1] == s2[j-1]){

                dp[i][j] = dp[i-1][j-1]; 
            }
            else{

                // Se forem diferentes, testamos os 3 caminhos e pegamos o mais barato
                dp[i][j] = min({

                    // 1. SUBSTITUIR a letra s1[i-1] pela letra s2[j-1]
                    dp[i-1][j-1] + custo_substituir(s1[i-1], s2[j-1]),

                    // 2. APAGAR a letra s1[i-1]
                    dp[i-1][j] + custo_apagar(s1[i-1]),

                    // 3. INSERIR a letra s2[j-1]
                    dp[i][j-1] + custo_inserir(s2[j-1])
                });
            }
        }
    }

    // Resposta final
    cout << dp[N][M] << '\n';

    return 0;
}