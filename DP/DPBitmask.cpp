#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

const int MAXK = 20; // Numero maximo de bits (2^20 eh o limite aceitavel)
int dp[1 << MAXK];

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; 
    // N = numero de itens, K = numero de requisitos (bits)
    cin >> N >> K;

    int max_mask = (1 << K);
    
    // Inicializa: custo INF para tudo, exceto nao ter nada (mask 0)
    for(int i = 0; i < max_mask; i++) dp[i] = INF;
    dp[0] = 0;

    for(int i = 0; i < N; i++){

        int custo;
        string s;
        cin >> custo >> s;

        // 1. Transforma os requisitos do item em uma mask
        int item_mask = 0;
        for(char c : s){
            // Se os requisitos forem 'A', 'B', 'C'...
            item_mask |= (1 << (c - 'A')); 
        }

        // 2. Atualiza a DP
        // Para garantir que nao usamos o mesmo item varias vezes na mesma transicao:
        // Iteramos de tras para frente (como no Knapsack 0/1)
        for(int mask = max_mask - 1; mask >= 0; mask--){

            if(dp[mask] == INF) continue;

            int nova_mask = mask | item_mask;
            dp[nova_mask] = min(dp[nova_mask], dp[mask] + custo);
        }
    }

    // A resposta eh a mascara com todos os K bits ligados
    int alvo = max_mask - 1;
    if(dp[alvo] == INF) cout << -1 << '\n';
    else cout << dp[alvo] << '\n';

    /* --- DICAS DE BITMASK ---
       1. (1 << K) - 1: Mascara com todos os K bits ligados (ex: K=3, mask=7).
       2. (mask >> i) & 1: Verifica se o i-esimo bit esta ligado.
       3. mask | (1 << i): Liga o i-esimo bit.
       4. mask & ~(1 << i): Desliga o i-esimo bit.
       5. mask ^ (1 << i): Inverte (flip) o i-esimo bit.
       6. __builtin_popcountll(mask): Conta quantos bits estao ligados (muito util!).
    */

    return 0;
}




#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define int long long
using namespace std;

int32_t main(){

    int N;
    cin>>N;

    vector<int> dp(8,INF);


    int custos[N];
    string vitaminas[N];

    for(int i=0;i<N;i++){

        cin>>custos[i];
        cin>>vitaminas[i];

    }



    dp[0]=0;

    for(int i=0;i<N;i++){

        int mask=0;

        for(char v:vitaminas[i]){

            if(v=='A') mask|=1;
            if(v=='B') mask|=2;
            if(v=='C') mask|=4;

        }

            for(int j=0;j<(1<<3);j++){

                int x=j|mask;
                dp[x]=min(dp[x],dp[j]+custos[i]);

            }

    }



    if(dp[7]==INF) cout<<-1;

    else cout<<dp[7];




}