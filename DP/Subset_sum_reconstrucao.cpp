#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1005;
const int MAX_SUM = 100010;

int a[MAXN];
bool dp[MAX_SUM];
int pai[MAX_SUM]; // Guarda o valor do item que nos fez chegar nessa soma

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, alvo;
    cin >> N >> alvo;

    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    for(int i=0; i<=alvo; i++){
        dp[i] = false;
        pai[i] = -1; // -1 significa que ainda nao chegamos nessa soma
    }
    
    dp[0] = true; 

    for(int i=0; i<N; i++){
        
        // Sempre de tras pra frente pra nao usar o item duas vezes
        for(int j=alvo; j>=a[i]; j--){
            
            // Se eu AINDA NAO formei a soma 'j', mas consigo formar 'j - a[i]'
            if(!dp[j] && dp[j - a[i]]){
                
                dp[j] = true;
                pai[j] = a[i]; // Salva que chegamos em 'j' usando o item 'a[i]'
            }
        }
    }

    if(!dp[alvo]){
        cout << "NO\n";
    } 
    else {
        cout << "YES\n";

        // --- Reconstrucao ---
        vector<int> escolhidos;
        int atual = alvo;
        
        while(atual > 0){
            // Olha quem nos trouxe pra soma 'atual' e guarda na resposta
            int item_usado = pai[atual];
            escolhidos.push_back(item_usado);
            
            // Subtrai o item pra voltar pro estado anterior
            atual -= item_usado; 
        }

        // Imprime os itens que formam a soma
        for(int i=0; i<escolhidos.size(); i++){
            cout << escolhidos[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}