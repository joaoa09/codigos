#include <bits/stdc++.h>
#define int long long
using namespace std;

int MOD=1e9+7;


int mod_mul(int a, int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

int mod_sub(int a,int b){
    return ((a%MOD)-(b%MOD)+MOD)%MOD;
}



int fexp(int a,int b){

    int res=1;

    a%=MOD;

    while(b>0){

        if(b%2==1) res=mod_mul(res,a);
        a=mod_mul(a,a);
        b>>=1;
    }
    return res;


}

int inv_mod(int n){
    return fexp(n,MOD-2);
}



int32_t main(){

    int t;
    cin>>t;
    while(t--){

        int N;
        cin>>N;

        int q=(N-1)*(N-2)/2;
        q=(q+MOD)%MOD;

        int limite=(N+1)/2;

        int ruim=3*(N-limite)*(N-limite-1)/2;

        int p=mod_sub(q,ruim);

        q=inv_mod(q);

        cout<<((p%MOD)*(q%MOD))%MOD<<'\n';


    }


}
