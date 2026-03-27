vector<int> toposort(int N){

    vector<int> grau(N+1,0);
    for(int i=1; i<=N; i++){

        for(int v:adj[i]) grau[v]++;
    }

    queue<int> q;
    for(int i=1; i<=N; i++){

        if(grau[i]==0) q.push(i);
    }

    vector<int> ordem;
    while(!q.empty()){

        int u=q.front();
        q.pop();
        ordem.push_back(u);

        for(int v:adj[u]){

            grau[v]--;
            if(grau[v]==0) q.push(v);
        }
    }

    if(ordem.size()<N) return {}; // Grafo tem ciclo!
    return ordem;
}