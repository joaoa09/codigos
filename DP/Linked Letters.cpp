#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5+30;

int pai[MAXN];
int sz[MAXN];

map<string,int> m;

void init(int n) {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;  
        sz[i] = 1;  
    }
}

int find(int v) {
    if(pai[v] == v) return v;
    return pai[v] = find(pai[v]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(sz[b] > sz[a]) swap(a, b);

    pai[b] = a;
    sz[a] += sz[b];
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,Q;
    cin>>N>>Q;

    string s;

    init(N+26);

    for(int i=1;i<=N;i++){

        cin>>s;

        m[s]=i;

        for(int j=0;j<s.size();j++){

            join(m[s],N+s[j]-'a'+1);
        }

    }

    string s1,s2;
    for(int i=0;i<Q;i++){

        cin>>s1>>s2;

        if(find(m[s1])!=find(m[s2])){
            cout<<"RYEI\n";
        }
        else{ 
            cout<<"LUA\n";
        }


    }







}