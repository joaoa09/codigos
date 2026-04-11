#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
        while(t--){
            
            int N,K;
            cin>>N>>K;

            int A,soma=0;

            for(int i=0;i<N;i++){

                cin>>A;
                soma+=A;
            }

            if(soma%2==1 || (N*K)%2==0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }


        }
}