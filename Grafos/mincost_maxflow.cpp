#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//ajustar conforme questão, qtd de vertices
const int MAXN=2010;
const ll INF=1e18;


//edge vai guardar o flow, o cap e o custo
struct Edge {

    int to;
    ll cap,flow;
    ll cost;
    int rev;
};

vector<Edge> adj[MAXN];
bool inq[MAXN];
int ptr[MAXN];
bool vis[MAXN];

//vetor que guarda o menor caminho saindo da source
ll dist[MAXN];

//matriz com os custos de cada par
ll custo[MAXN][MAXN];

//-cost na aresta de volta
void add_edge(int u, int v, ll cap,ll cost){

    adj[u].push_back({v,cap,0,cost,(int)adj[v].size()});
    adj[v].push_back({u,cap,0,-cost,(int)adj[u].size()-1});
}

void add_edge_uni(int u, int v, ll cap,ll cost){

    adj[u].push_back({v,cap,0,cost,(int)adj[v].size()});
    adj[v].push_back({u,0,0,-cost,(int)adj[u].size()-1});
}

//SPFA para achar o menor caminho ao invés da BFS comum
//inq diz se o vértice já tá na fila
bool spfa(int s, int t){

    fill(dist,dist+MAXN,INF);
    fill(inq,inq+MAXN,false);

    dist[s]=0;
    queue<int> q;
    q.push(s);
    inq[s]=true;

    while(!q.empty()){

        auto u=q.front();
        q.pop();
        inq[u]=false;

        for(auto& edge:adj[u]){

            if(edge.cap-edge.flow>0 && dist[edge.to]>dist[u]+edge.cost){

                dist[edge.to]=dist[u]+edge.cost;
                
                if(!inq[edge.to]){
                    q.push(edge.to);
                    inq[edge.to]=true;
                }
            }
        }
    }

    return dist[t]!=INF;
}

//array de visitados para não estourar
ll dfs(int u, int t, ll pushed){

    if(pushed==0) return 0;
    if(u==t) return pushed;

    vis[u]=true;

    for(int& cid=ptr[u];cid<adj[u].size();++cid){

        auto& edge=adj[u][cid];
        int v=edge.to;

        if(dist[u]+edge.cost != dist[v] || edge.cap-edge.flow==0 || vis[v]) continue;

        ll push=dfs(v,t,min(pushed,edge.cap-edge.flow));
        if(push==0) continue;

        edge.flow+=push;
        adj[v][edge.rev].flow-=push;

        vis[u]=false;
        return push;
    }
    vis[u]=false;
    return 0;
}

//cost = menor custo para o maxflow
//fluxo = maxflow
pair<ll,ll> dinic(int s, int t){

    ll fluxo=0;
    ll cost=0;

    while(spfa(s,t)){

        fill(ptr,ptr+MAXN,0);

        while(ll pushed=dfs(s,t,INF)){
            fluxo+=pushed;
            cost+=pushed*dist[t];
        }
    }
    return {fluxo,cost};

}