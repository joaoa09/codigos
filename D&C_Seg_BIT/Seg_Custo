#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

struct Node {
    int esq=INF; 
    int dir=INF;

    Node operator + (const Node& a) const {
        Node resp;

        resp.esq=min(esq,a.esq);
        resp.dir=min(dir,a.dir);

        return resp;
    }
};

struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(int n) {
        this->n = n;
        tree.resize(4*n+5);
    }

    void build(int atual, int l, int r, const vector<int>& V){
        if(l==r){
            tree[atual].esq=V[l]-l;
            tree[atual].dir=V[l]+l;
            return;
        }

        int mid=(l+r)/2;

        build(2*atual, l, mid, V);
        build(2*atual+1, mid+1, r, V);

        tree[atual] = tree[2*atual] + tree[2*atual+1];
    }

    void update(int atual, int l, int r, int id, int valor){
        if(l==r){
            tree[atual].esq = valor-l;
            tree[atual].dir = valor+l;
            return;
        }

        int mid=(l+r)/2;

        if(id<=mid) update(2*atual, l, mid, id, valor);
        else update(2*atual+1, mid+1, r, id, valor);

        tree[atual] = tree[2*atual] + tree[2*atual+1];
    }

    Node query(int atual, int l, int r, int p, int q){
        if(p<=l && r<=q) return tree[atual];

        int mid=(l+r)/2;

        if(q<=mid) return query(2*atual, l, mid, p, q);
        if(p>mid) return query(2*atual+1, mid+1, r, p, q);

        return query(2*atual, l, mid, p, q) + query(2*atual+1, mid+1, r, p, q);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> V(n+1);
    for(int i=1; i<=n; i++){
        cin >> V[i];
    }

    SegTree seg(n);
    seg.build(1, 1, n, V);

    for(int i=0;i<q;i++){
        int op;
        cin>>op;

        if(op==1){
            int id,valor;
            cin>>id>>valor;
            seg.update(1,1,n,id,valor);
        }
        else{
            int k;
            cin>>k;
            
            Node node_esq=seg.query(1,1,n,1,k);
            int esquerda=node_esq.esq+k;
            
            Node node_dir=seg.query(1,1,n,k,n);
            int direita=node_dir.dir-k;
            
            cout<<min(esquerda,direita)<<'\n';
        }
    }

    return 0;
}