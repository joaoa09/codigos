#include <bits/stdc++.h>
#define int long long
using namespace std;

// O array Z guarda em z[i] o tamanho do maior prefixo comum 
// entre a string inteira s[0...n-1] e o sufixo s[i...n-1].
vector<int> z_function(string s){

    int n=s.size();
    vector<int> z(n,0);
    
    // [l, r] mantem a "Z-box", que e o intervalo mais a direita
    // que e igual a um prefixo de s.
    int l=0,r=0;
    
    for(int i=1;i<n;i++){

        // Se 'i' esta dentro da nossa Z-box atual, podemos aproveitar 
        // o trabalho ja feito anteriormente no prefixo.
        if(i<=r){
            // z[i-l] e o valor correspondente no prefixo.
            // r-i+1 e o limite do que temos certeza que da match dentro da caixa.
            z[i]=min(r-i+1,z[i-l]);
        }
        
        // Tenta expandir o match ingenuamente alem do que ja sabemos.
        // Se bater com o prefixo, aumenta z[i].
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){

            z[i]++;
        }
        
        // Se o novo match ultrapassar o limite direito da caixa antiga,
        // atualizamos a Z-box para a nova fronteira.
        if(i+z[i]-1>r){

            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string P,T;
    cin>>P>>T;

    // TRUQUE MAGICO: P + "#" + T
    // O '#' atua como um separador que nunca aparece nas strings.
    // Isso garante que os valores de z[i] na parte do texto nunca
    // vao ultrapassar o tamanho de P.
    string s=P+"#"+T;
    vector<int> z=z_function(s);

    int szP=P.size();
    
    // Percorremos o array z. Como a string s comeca com P,
    // se acharmos um z[i] == tamanho de P, significa que o padrao P
    // apareceu por completo a partir do indice 'i'.
    for(int i=0;i<z.size();i++){

        if(z[i]==szP){
            
            // i é a posição na string concatenada 's'.
            // Para achar o indice real em 'T', subtraimos o tamanho do padrao (szP) 
            // e mais 1 por causa do separador '#'.
            cout<<"Padrao encontrado no indice: "<<i-szP-1<<"\n";
        }
    }

    return 0;
}