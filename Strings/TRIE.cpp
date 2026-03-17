#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5+10;
int trie[MAXN][26];
int is_word[MAXN];
int count_pref[MAXN];
int nodes=0;

void insert(string s){

    int u=0;
    count_pref[u]++;
    for(int i=0;i<s.size();i++){

        int c=s[i]-'a';
        if(trie[u][c]==0){

            trie[u][c]=++nodes;
        }
        u=trie[u][c];
        count_pref[u]++;
    }
    is_word[u]++;
}

int query_word(string s){

    int u=0;
    for(int i=0;i<s.size();i++){

        int c=s[i]-'a';
        if(trie[u][c]==0) return 0;
        u=trie[u][c];
    }
    return is_word[u];
}

int query_pref(string s){

    int u=0;
    for(int i=0;i<s.size();i++){

        int c=s[i]-'a';
        if(trie[u][c]==0) return 0;
        u=trie[u][c];
    }
    return count_pref[u];
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);




    
    return 0;
}