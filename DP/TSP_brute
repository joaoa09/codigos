#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin>>n)) return 0;

    int dist[15][15];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }

    // Se so tem 1 cidade, nao ha custo de viagem
    if(n==1){
        cout<<0<<'\n';
        return 0;
    }

    vector<int> v;
    
    // Fixamos a cidade 0 como inicio. 
    // Colocamos apenas as outras cidades no vector para permutar.
    for(int i=1;i<n;i++){
        v.push_back(i);
    }

    int ans=INF;

    do{
        int custo_atual=0;
        int cidade_atual=0; // Comecamos sempre na cidade 0

        // Percorre a permutacao atual
        for(int i=0;i<v.size();i++){
            
            int proxima=v[i];
            custo_atual+=dist[cidade_atual][proxima];
            cidade_atual=proxima;
            
        }

        // Soma o custo de voltar para a cidade 0 para fechar o ciclo
        custo_atual+=dist[cidade_atual][0];

        ans=min(ans,custo_atual);

    }while(next_permutation(v.begin(),v.end()));

    cout<<ans<<'\n';

    return 0;

}