#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 3005;

// Como é N <= 3000, matriz global de 3000x3000 aguenta de boa sem MLE
int dp[MAXN][MAXN];

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int N = s.size();
    int M = t.size();

    // 1. PREENCHIMENTO DA TABELA DP
    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= M; j++){

            // Se as letras baterem
            if(s[i-1] == t[j-1]){

                dp[i][j] = dp[i-1][j-1] + 1; 
            }
            // Se as letras forem diferentes, herda o melhor valor
            else{

                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
    }

    // 2. RECONSTRUCAO DA STRING (Backtracking na Tabela)
    string ans = "";
    int i = N, j = M;

    while(i > 0 && j > 0){

        // Se as letras sao iguais, ela faz parte da resposta
        if(s[i-1] == t[j-1]){

            ans += s[i-1];
            i--; 
            j--;
        }
        // Se nao sao iguais, a gente anda pra onde o valor da matriz for maior
        else if(dp[i-1][j] > dp[i][j-1]){

            i--; // O melhor valor veio de cima (ignorou a letra de 's')
        }
        else{

            j--; // O melhor valor veio da esquerda (ignorou a letra de 't')
        }
    }

    // Como voltamos do fim da matriz pro começo, invertemos a string
    reverse(ans.begin(), ans.end());

    // Se o problema pedir só o tamanho da LCS, basta imprimir dp[N][M]
    cout << ans << '\n';

    return 0;
}