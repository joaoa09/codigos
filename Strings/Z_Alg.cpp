#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> z_function(string s){

    int n=s.size();
    vector<int> z(n,0);
    int l=0,r=0;
    
    for(int i=1;i<n;i++){

        if(i<=r){

            z[i]=min(r-i+1,z[i-l]);
        }
        
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){

            z[i]++;
        }
        
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

    string s=P+"#"+T;
    vector<int> z=z_function(s);

    int szP=P.size();
    for(int i=0;i<z.size();i++){

        if(z[i]==szP){
            
            cout<<"Padrao encontrado no indice: "<<i-szP-1<<"\n";
        }
    }

    return 0;
}