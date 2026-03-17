#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=6e6+10; 
int trie[MAXN][2];
int nodes=0;

void insert(int x){

    int u=0;
    for(int i=60;i>=0;i--){

        int b=(x>>i)&1;
        if(trie[u][b]==0){

            trie[u][b]=++nodes;
        }
        u=trie[u][b];
    }
}

int get_max(int x){

    int u=0,ans=0;
    for(int i=60;i>=0;i--){

        int b=(x>>i)&1;
        if(trie[u][1-b]!=0){

            ans|=(1LL<<i);
            u=trie[u][1-b];
        }
        else{

            u=trie[u][b];
        }
    }
    return ans;
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}