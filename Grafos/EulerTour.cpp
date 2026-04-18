int timer=1;
int tin[MAXN];
int tout[MAXN];

void euler_tour(int node, int prev){

    tin[node]=timer++;
    for(int v:adj[node]){

        if(v!=prev){
            euler_tour(v,node);
        }
    }
    tout[node]=timer;
}