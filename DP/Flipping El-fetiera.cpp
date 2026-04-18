#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){

    freopen("fetiera.in","r",stdin);


    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
        while(t--){
            
            int N,K;
            cin>>N>>K;

            int m[N][N];

            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){

                    cin>>m[i][j];
                }
            }

            double total=((N*(N+1))/2)*((N*(N+1))/2);

            double resp=0;

            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){

                    double c=i*j*(N-i+1)*(N-j+1);

                    double p=c/total;

                    double dp[K+1];

                    dp[0]=1;
                    for(int l=1;l<=K;l++){

                        dp[l]=(dp[l-1]*(1.0-p)) + (1.0-dp[l-1])*p;
                    }

                    if(m[i-1][j-1]==1){
                        resp+=dp[K];
                    }
                    else{
                        resp+=(1-dp[K]);
                    }

                    
                }
            }

            cout<<setprecision(5)<<fixed<<resp<<'\n';


        }
}