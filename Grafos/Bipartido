const int MAXN=2e5+10;
vector<int> adj[MAXN];
int cor[MAXN]; // Inicializar com -1

bool bfs_bipartido(int s){

    queue<int> q;
    q.push(s);
    cor[s]=0;

    while(!q.empty()){

        int u=q.front();
        q.pop();

        for(int v:adj[u]){

            if(cor[v]==-1){

                cor[v]=1-cor[u];
                q.push(v);
            }
            else if(cor[v]==cor[u]){

                return false;
            }
        }
    }
    return true;
}