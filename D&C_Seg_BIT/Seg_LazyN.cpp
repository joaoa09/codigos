#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl '\n'

const ll MOD = 1e9+7;

ll mod_add(ll a, ll b){ return (a%MOD + b%MOD +2*MOD)%MOD; }
ll mod_mul(ll a, ll b){ return (a%MOD * b%MOD)%MOD; }


struct Node {

    int soma=0;
    int soma_q=0;
    int lazy=0;

    Node operator + (const Node& a) const {

        Node resp;
        resp.soma=mod_add(a.soma, soma);
        resp.soma_q=mod_add(a.soma_q, soma_q);

        return resp;
    }
};

struct Segtree{

    int n;
    vector<Node> tree;

    Segtree(int n){

        this->n=n;

        tree.resize(4*n+5);
    }

    void build(int atual, int l, int r, vector<int>& v){

        if(l==r){
            tree[atual].soma=v[l];
            tree[atual].soma_q=mod_mul(v[l], v[l]);
            return;
        }

        int mid=(l+r)/2;

        build(2*atual,l,mid,v);
        build(2*atual+1,mid+1,r,v);

        tree[atual] = tree[2*atual] + tree[2*atual+1];
    }

    void push(int atual, int l, int r){

        if(tree[atual].lazy==0) return;


        tree[atual].soma_q = mod_add(tree[atual].soma_q, mod_mul(mod_mul((ll)(r-l+1), tree[atual].lazy), tree[atual].lazy));
        tree[atual].soma_q = mod_add(tree[atual].soma_q, mod_mul(2ll, mod_mul(tree[atual].lazy, tree[atual].soma)));


        // tree[atual].soma_q+=(r-l+1)*tree[atual].lazy*tree[atual].lazy + 2*tree[atual].lazy*(tree[atual].soma);


        tree[atual].soma = mod_add(tree[atual].soma, mod_mul((ll)(r - l + 1), tree[atual].lazy));
        // tree[atual].soma+=(r-l+1)*tree[atual].lazy;

        if(l!=r){
            tree[2*atual].lazy+=tree[atual].lazy;
            tree[2*atual+1].lazy+=tree[atual].lazy;

        }

        tree[atual].lazy=0;
    }

    void update(int atual, int l, int r, int p, int q, int valor){

        push(atual,l,r);

        if(r<p || l>q) return;

        if(p<=l && r<=q){

            tree[atual].lazy+=valor;
            push(atual,l,r);
            return;

        }

        int mid=(l+r)/2;

        update(2*atual,l,mid,p,q,valor);
        update(2*atual+1,mid+1,r,p,q,valor);

        tree[atual]=tree[2*atual]+tree[2*atual+1];
    }

    Node query(int atual, int l, int r,int p, int q){

        push(atual, l, r);

        if(r<p || l>q){

            Node nulo;
            nulo.soma=0;
            nulo.soma_q=0;
            return nulo;
        }


        if(p<=l && r<=q) return tree[atual];

        int mid=(l+r)/2;

        Node esq = query(2*atual, l, mid, p, q);
        Node dir = query(2*atual+1, mid+1, r, p, q);
        
        return esq+dir;
    }


};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,Q;
    cin>>n>>Q;

    vector<int> v(n+1,0);

    for(int i=1;i<=n;i++) cin>>v[i];

    Segtree seg(n);

    seg.build(1,1,n,v);

    for(int i=0;i<Q;i++){

        char op;
        cin>>op;

        if(op=='u'){

            int p,q,valor;
            cin>>p>>q>>valor;

            seg.update(1,1,n,p,q,valor);
        }

        else{

            int p,q;
            cin>>p>>q;

            Node resp=seg.query(1,1,n,p,q);
            cout<<resp.soma_q<<"\n";
        }
    }

    return 0;
}