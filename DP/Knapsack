#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXW = 100010; // Capacidade maxima da mochila
int dp[MAXW];
int peso[105], valor[105];

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin>>N>>W;

    for(int i=0; i<N; i++){
        
        cin>>peso[i]>>valor[i];
    }

    // dp[j] armazena o MAIOR VALOR possivel usando peso j
    // A matriz global ja inicializa tudo com 0.

    for(int i=0; i<N; i++){

        for(int j=W; j>=peso[i]; j--){

            dp[j] = max(dp[j], dp[j - peso[i]] + valor[i]);
        }
    }

    cout<<dp[W]<<'\n';
    return 0;
}