int pai[MAXN];
int estado[MAXN]; // 0: branco, 1: cinza (visitando), 2: preto (finalizado)

bool dfs_ciclo(int u){

    estado[u]=1;
    for(int v:adj[u]){

        if(estado[v]==1){

            // Achou ciclo! Se quiser o caminho, o ciclo esta entre v e u
            return true;
        }
        if(estado[v]==0){

            pai[v]=u;
            if(dfs_ciclo(v)) return true;
        }
    }
    estado[u]=2;
    return false;
}