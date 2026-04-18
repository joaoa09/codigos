int lca(int u, int v){

    if(prof[u]<prof[v]){
        swap(u,v);
    }

    int dist=prof[u]-prof[v];

    for(int i=0;i<31;i++){
        if(dist & (1<<i)){

            u=dp[i][u];

        }
    }

    if(u==v){
        return u;
    }

    
    for(int i=30;i>=0;i--){
        if(dp[i][u]!=dp[i][v]){
            u=dp[i][u];
            v=dp[i][v];
        }
    }

    return dp[0][u];



}

void dfs(int u, int pai, int profundidade){
    dp[0][u]=pai;
    prof[u]=profundidade;

    for(int v:adj[u]){

        if(v==pai){
            continue;
        }

        dfs(v,u,profundidade+1);
    }
}

for(int i = 1; i <=30; i++){
    for(int j = 1; j <=n; j++){
        dp[i][j] = dp[i-1][dp[i-1][j]];
        }
}

