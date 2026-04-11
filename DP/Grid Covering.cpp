#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
        while(t--){
            
            int n,m,a,b;
            cin>>n>>m>>a>>b;

            if(gcd(a,n)>1 || gcd(b,m)>1 || gcd(n,m)>2){
                cout<<"NO\n";
            }
            
            else{
                cout<<"YES\n";
            }

        }
}