const int MAXN=1e5+5;
vector<int> adj[MAXN];
int dist[MAXN];

void bfs(int start){

    // Inicializa tudo com -1 (nao visitado)
    memset(dist,-1,sizeof(dist));
    
    queue<int> q;
    q.push(start);
    dist[start]=0;

    while(!q.empty()){
        
        int u=q.front();
        q.pop();

        for(int v:adj[u]){
            
            // Se ainda nao foi visitado
            if(dist[v]==-1){
                
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}




const int INF=1e9+7; // Ou o teu 0x3f3f3f3f3f3f3f3f se usares long long
vector<pair<int,int>> adj_peso[MAXN]; // {vizinho, peso}
int dist01[MAXN];

void bfs01(int start){

    for(int i=0;i<MAXN;i++){
        dist01[i]=INF;
    }
    
    deque<int> dq;
    dq.push_back(start);
    dist01[start]=0;

    while(!dq.empty()){
        
        int u=dq.front();
        dq.pop_front();

        for(auto edge:adj_peso[u]){
            
            int v=edge.first;
            int w=edge.second; // w so pode ser 0 ou 1

            // Relaxamento: se achei um caminho mais curto
            if(dist01[u]+w<dist01[v]){
                
                dist01[v]=dist01[u]+w;
                
                if(w==0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
}