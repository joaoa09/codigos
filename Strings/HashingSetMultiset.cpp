#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int MAXN=1e5+10;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ull rnd[MAXN];
ull set_hash_A=0,set_hash_B=0;
ull multiset_hash_A=0,multiset_hash_B=0;

int freq_set_A[MAXN],freq_set_B[MAXN];

//set ({a,a,b}={a,b})
void add_set_A(int x){

    if(freq_set_A[x]==0){

        set_hash_A^=rnd[x];
    }
    freq_set_A[x]++;
}

void add_set_B(int x){

    if(freq_set_B[x]==0){

        set_hash_B^=rnd[x];
    }
    freq_set_B[x]++;
}




//set ({a,a,b}!={a,b}, precisa ter a msm quantidade de cada)
void add_multiset_A(int x){

    multiset_hash_A+=rnd[x];
}

void add_multiset_B(int x){

    multiset_hash_B+=rnd[x];
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0;i<MAXN;i++){

        rnd[i]=rng();
    }

    string s1;
    string s2;


    for(int i=0;i<s1.size();i++){

        add_set_A(s1[i]);
        add_multiset_A(s1[i]);
    }

    for(int i=0;i<s2.size();i++){

        add_set_B(s2[i]);
        add_multiset_B(s2[i]);
    }

    //agr so comparar as variaveis globais e descobrir se o set ou o multiset de palavras é igual.

    
    return 0;
}