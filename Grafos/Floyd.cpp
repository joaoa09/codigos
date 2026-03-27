int dist[MAXN][MAXN];

void floyd_warshall(int N){

    // Inicializar dist[i][i]=0 e o resto com INF ou o peso da aresta
    for(int k=1; k<=N; k++){

        for(int i=1; i<=N; i++){

            for(int j=1; j<=N; j++){

                if(dist[i][k]!=INF && dist[k][j]!=INF){

                    if(dist[i][k]+dist[k][j]<dist[i][j]){

                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }
}