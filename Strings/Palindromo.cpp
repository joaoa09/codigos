#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6+10;

// Bases e Modulos diferentes para evitar colisoes (Double Hashing)
const int P1=31;
const int P2=37;
const int M1=1e9+33;
const int M2=1e9+93;

int h1[MAXN],h2[MAXN],p1[MAXN],p2[MAXN];

// Retorna o hash da substring [i...j] em O(1)
pair<int,int> substr_hash(int i,int j){
    int len=j-i+1;
    int hash1=(((h1[j+1]-(h1[i]*p1[len])%M1)%M1)+M1)%M1;
    int hash2=(((h2[j+1]-(h2[i]*p2[len])%M2)%M2)+M2)%M2;
    return {hash1,hash2};
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Pre-computacao das potencias das bases
    p1[0]=1;
    p2[0]=1;
    for(int i=1;i<MAXN;i++){
        p1[i]=(p1[i-1]*P1)%M1;
        p2[i]=(p2[i-1]*P2)%M2;
    }

    int n,x; // n = tamanho da string, x = tamanho do palindromo desejado
    cin>>n>>x;

    string s;
    cin>>s;

    // A MÁGICA: Criamos uma string 'f' que contem S + '#' + REVERSE(S)
    string s2 = s;
    reverse(s2.begin(),s2.end());
    string f=s+'#'+s2;
    int N=f.size();

    // Calculamos o hash de prefixo da string zona 'f'
    h1[0]=0;
    h2[0]=0;
    for(int i=0;i<N;i++){
        int val=f[i];
        h1[i+1]=(h1[i]*P1+val)%M1;
        h2[i+1]=(h2[i]*P2+val)%M2;
    }

    // Deslizamos uma janela de tamanho 'x' na string original
    for(int i=0;i<=n-x;i++){
        int tam=i+x-1; // Fim da substring na string original

        // Mapeamento: onde a substring [i...tam] estaria na parte REVERSA de 'f'
        int l=N-1-tam;
        int r=N-1-i;

        // Se o hash da ida for igual ao hash da volta, encontramos um palindromo de tamanho x
        if(substr_hash(i,tam)==substr_hash(l,r)){
            cout<<"Accept";
            return 0;
        }
    }

    cout<<"Reject";

    return 0;
}