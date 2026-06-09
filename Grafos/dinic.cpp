#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

const int MAXN=2105;
const int INF=1e18;

struct Edge {

    int to;
    ll cap,flow;
    int rev;
};

vector<Edge> adj[MAXN];
int level[MAXN];
int ptr[MAXN];

void add_edge(int u, int v, ll cap){

    adj[u].push_back({v,cap,0,(int)adj[v].size()});
    adj[v].push_back({u,cap,0,(int)adj[u].size()-1});
}

void add_edge_uni(int u, int v, ll cap){

    adj[u].push_back({v,cap,0,(int)adj[v].size()});
    adj[v].push_back({u,0,0,(int)adj[u].size()-1});
}


bool bfs(int s, int t){

    fill(level, level+MAXN,-1);

    level[s]=0;
    queue<int> q;
    q.push(s);

    while(!q.empty()){

        int u=q.front();
        q.pop();

        for(auto& edge:adj[u]){

            if(edge.cap-edge.flow>0 && level[edge.to]==-1){

                level[edge.to]=level[u]+1;
                q.push(edge.to);
            }
        }
    }

    return level[t]!=-1;
}


ll dfs(int u, int t, ll pushed){

    if(pushed==0) return 0;
    if(u==t) return pushed;

    for(int& cid=ptr[u];cid<adj[u].size();++cid){

        auto& edge=adj[u][cid];
        int v=edge.to;

        if(level[u]+1 != level[v] || edge.cap-edge.flow==0) continue;

        ll push=dfs(v,t,min(pushed,edge.cap-edge.flow));
        if(push==0) continue;

        edge.flow+=push;
        adj[v][edge.rev].flow-=push;
        return push;
    }
    return 0;
}

ll dinic(int s, int t){

    ll flow=0;

    while(bfs(s,t)){

        fill(ptr,ptr+MAXN,0);

        while(ll pushed=dfs(s,t,INF)){
            flow+=pushed;
        }
    }
    return flow;

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin>>N>>M;

    vector<pair<int,int>> v;

    for(int i=0;i<M;i++){

        int A,B;
        cin>>A>>B;

        v.push_back({A,B});
    }

    for(auto [x,y]:v){

        add_edge(x,y,1);
    }

    
}