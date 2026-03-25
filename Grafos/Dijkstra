const int INF=1e18;
vector<pair<int,int>> adj[MAXN];
int dist[MAXN];

void dijkstra(int s){

    for(int i=0; i<MAXN; i++) dist[i]=INF;
    dist[s]=0;

    // PQ padrao de C++ eh Max-Heap (tira o maior primeiro)
    priority_queue<pair<int,int>> pq;
    pq.push({0,s}); // Peso 0 nao precisa de sinal

    while(!pq.empty()){

        int d=-pq.top().first; // Desinverte o sinal ao tirar
        int u=pq.top().second;
        pq.pop();

        if(d>dist[u]) continue;

        for(auto edge:adj[u]){

            int v=edge.first;
            int w=edge.second;

            if(dist[u]+w<dist[v]){

                dist[v]=dist[u]+w;
                pq.push({-dist[v],v}); // Inverte o sinal ao colocar
            }
        }
    }
}