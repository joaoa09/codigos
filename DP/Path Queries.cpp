#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e5+10;

int n,Q;

struct Node {
    int val=0;


    Node operator + (const Node& a) const {
        Node resp;
        resp.val=val+a.val;
        return resp;
    }
};


int tin[MAXN];
int tout[MAXN];
int timer=1;

vector<int> adj[MAXN];

struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(int n) {
        this->n=n;
        tree.resize(4*n+5);
    }


    void build(int atual,int l,int r,const vector<int>& V){
        if(l==r){
            tree[atual].val=V[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*atual,l,mid,V);
        build(2*atual+1,mid+1,r,V);
        tree[atual]=tree[2*atual]+tree[2*atual+1];
    }


    void update(int atual,int l,int r,int id,int valor){
        if(l==r){
            tree[atual].val=valor;
            return;
        }
        int mid=(l+r)/2;
        if(id<=mid) update(2*atual,l,mid,id,valor);
        else update(2*atual+1,mid+1,r,id,valor);
        tree[atual]=tree[2*atual]+tree[2*atual+1];
    }

    Node query(int atual,int l,int r,int p,int q){
        if(p<=l && r<=q) return tree[atual];
        int mid=(l+r)/2;
        if(q<=mid) return query(2*atual,l,mid,p,q);
        if(p>mid) return query(2*atual+1,mid+1,r,p,q);
        return query(2*atual,l,mid,p,q)+query(2*atual+1,mid+1,r,p,q);
    }
};


void euler_tour(int node, int prev){

    tin[node]=timer++;
    for(int v:adj[node]){

        if(v!=prev){
            euler_tour(v,node);
        }
    }
    tout[node]=timer++;
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin>>n>>Q;

    int val[n+1];

    for(int i=0;i<n;i++){

        cin>>val[i+1];
    }

    int A,B,C;
    for(int i=0;i<n-1;i++){

        cin>>A>>B;

        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    SegTree seg(4*MAXN);

    euler_tour(1,0);

    vector<int> v(2*n+1,0);

    for(int i=1;i<=n;i++){
        v[tin[i]]=val[i];
        v[tout[i]]=-val[i];
    }

    seg.build(1,1,2*n,v);

    for(int i=0;i<Q;i++){

        cin>>A;

        if(A==1){

            cin>>B>>C;

            seg.update(1,1,2*n,tin[B],C);
            seg.update(1,1,2*n,tout[B],-C);
        }
        else{

            cin>>B;
            
            Node resposta=seg.query(1,1,2*n,1,tin[B]);
            cout<<resposta.val<<"\n";
        }
    }
}
