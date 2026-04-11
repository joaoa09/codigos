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

            vector<int> v(N,0);

            for(int i=0;i<N;i++){

                cin>>v[i];
            }

            set<int> s;
            int A;
            for(int i=0;i<K;i++){
                cin>>A;
                s.insert(A-1);
            }

            int inv=0;
            int resp=0;
            int total=0;

            for(int i=0;i<=N;i++){


                if(i==0){
                    
                    if(v[*s.begin()]!=v[i]){
                        inv++;
                        total++;
                    }
                }

                else if(i==N){
                    
                    if(v[*s.begin()]!=v[i-1]){
                        inv++;
                        total++;
                    }
                }

                else{

                    if(v[i-1]!=v[i]){
                        
                        inv++;
                        total++;
                    }

                }

                if(s.find(i)!=s.end()){

                    resp=max(resp,inv);
                    inv=0;
                }

            }

            resp=max(resp,inv);

            resp=max(resp,(total+1)/2);

            cout<<resp<<'\n';

        }
}