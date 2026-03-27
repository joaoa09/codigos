#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(!(cin>>t)) return 0;

    while(t--){

        int N;
        cin>>N;

        // Trocado para vector para evitar Stack Overflow em N grandes
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }

        vector<int> pref(N+1);
        pref[0]=INF;
        
        vector<int> suf(N+1);
        suf[N]=0;

        for(int i=0;i<N;i++){
            pref[i+1]=min(pref[i],A[i]);
        }

        for(int i=N;i>0;i--){
            suf[i-1]=max(suf[i],A[i-1]);
        }

        for(int i=0;i<N;i++){

            if(A[i]==pref[i+1] || A[i]==suf[i]) cout<<1;
            else cout<<0;
        }
        cout<<'\n';
    }
    
    return 0;
}