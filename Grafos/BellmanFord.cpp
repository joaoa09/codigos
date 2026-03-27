struct Edge { int u,v,w; };
vector<Edge> edges;

bool bellman_ford(int N,int s){

    for(int i=1; i<=N; i++) dist[i]=INF;
    dist[s]=0;

    // Roda N-1 vezes
    for(int i=1; i<=N-1; i++){

        for(auto e:edges){

            if(dist[e.u]!=INF && dist[e.u]+e.w<dist[e.v]){

                dist[e.v]=dist[e.u]+e.w;
            }
        }
    }

    // Se na N-esima vez ainda der pra relaxar, tem ciclo negativo
    for(auto e:edges){

        if(dist[e.u]!=INF && dist[e.u]+e.w<dist[e.v]) return true; 
    }
    return false;
}