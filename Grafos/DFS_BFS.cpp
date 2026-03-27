#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e5+10;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int u){

    vis[u]=true;
    for(int v:adj[u]){

        if(!vis[v]){

            dfs(v);
        }
    }
}

void bfs(int s){

    queue<int> q;
    q.push(s);
    vis[s]=true;

    while(!q.empty()){

        int u=q.front();
        q.pop();

        for(int v:adj[u]){

            if(!vis[v]){

                vis[v]=true;
                q.push(v);
            }
        }
    }
}