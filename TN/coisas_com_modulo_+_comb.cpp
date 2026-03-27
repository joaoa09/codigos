#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=1e9+7;
const int MAXN=1e6+5; // Ajuste o MAXN conforme a questao

int mod_mul(int a,int b){return ((a%MOD)*(b%MOD))%MOD;}
int mod_add(int a,int b){return ((a%MOD)+(b%MOD))%MOD;}
int mod_sub(int a,int b){return ((a%MOD)-(b%MOD)+MOD)%MOD;}

// Exponenciacao Binaria: a^b % MOD - O(log B)
int fexp(int a,int b){
    int res=1;
    a%=MOD;
    while(b>0){
        if(b%2==1) res=mod_mul(res,a);
        a=mod_mul(a,a);
        b/=2;
    }
    return res;
}

// Inverso Modular: Funciona se MOD for PRIMO (Teorema de Fermat)
int inv_mod(int n){return fexp(n,MOD-2);}

// Combinacao (nCr) com pre-processamento de fatorial
int fact[MAXN],invFact[MAXN];

void precompute_nCr(){
    fact[0]=1;
    for(int i=1;i<MAXN;i++) fact[i]=mod_mul(fact[i-1],i);
    invFact[MAXN-1]=inv_mod(fact[MAXN-1]);
    for(int i=MAXN-2;i>=0;i--) invFact[i]=mod_mul(invFact[i+1],i+1);
}

int nCr(int n,int r){
    if(r<0 || r>n) return 0;
    return mod_mul(fact[n],mod_mul(invFact[r],invFact[n-r]));
}