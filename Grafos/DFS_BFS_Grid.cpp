const int MAXN=1005;
int grid[MAXN][MAXN]; 
int dist[MAXN][MAXN];
int N,M;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

void dfs_grid(int x,int y){

    dist[x][y]=0; 

    for(int i=0;i<4;i++){

        int nx=x+dx[i],ny=y+dy[i];

        if(nx>=0 && nx<N && ny>=0 && ny<M && grid[nx][ny]!='#' && dist[nx][ny]==-1){

            dist[nx][ny]=dist[x][y]+1;
            dfs_grid(nx,ny);
        }
    }
}

void bfs_grid(int sx,int sy){

    queue<pair<int,int>> q;
    q.push({sx,sy});
    dist[sx][sy]=0;

    while(!q.empty()){

        auto [x,y]=q.front();
        q.pop();

        for(int i=0;i<4;i++){

            int nx=x+dx[i],ny=y+dy[i];

            if(nx>=0 && nx<N && ny>=0 && ny<M && grid[nx][ny]!='#' && dist[nx][ny]==-1){

                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}