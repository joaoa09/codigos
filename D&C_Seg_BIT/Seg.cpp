#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF=1e18;

/*

struct Node {
    int soma=0,mpref=0,msuf=0,ans=0;
    Node operator + (const Node& a) const {
        Node resp;
        resp.soma=soma+a.soma;
        resp.mpref=max(mpref,soma+a.mpref);
        resp.msuf=max(a.msuf,msuf+a.soma);
        resp.ans=max({ans,a.ans,msuf+a.mpref});
        return resp;
    }
};

*/




// Estrutura do No: Altere aqui conforme o que a SegTree deve guardar
struct Node {
    int val=INF; // Ex: INF para Min, -INF para Max, 0 para Soma

    // Operacao de uniao (Merge) de dois nos
    Node operator + (const Node& a) const {
        Node resp;
        resp.val=min(val,a.val); // Ex: min, max, ou val+a.val
        return resp;
    }
};

struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(int n) {
        this->n=n;
        tree.resize(4*n+5);
    }

    // Constroi a arvore a partir de um vector V (1-indexed)
    void build(int atual,int l,int r,const vector<int>& V){
        if(l==r){
            tree[atual].val=V[l]; // Altere aqui se for calculo especial (ex: V[l]-l)
            return;
        }
        int mid=(l+r)/2;
        build(2*atual,l,mid,V);
        build(2*atual+1,mid+1,r,V);
        tree[atual]=tree[2*atual]+tree[2*atual+1];
    }

    // Atualizacao de um ponto (id) para um novo valor
    void update(int atual,int l,int r,int id,int valor){
        if(l==r){
            tree[atual].val=valor; // Altere aqui se o update for especial
            return;
        }
        int mid=(l+r)/2;
        if(id<=mid) update(2*atual,l,mid,id,valor);
        else update(2*atual+1,mid+1,r,id,valor);
        tree[atual]=tree[2*atual]+tree[2*atual+1];
    }

    // Consulta no intervalo [p, q]
    Node query(int atual,int l,int r,int p,int q){
        if(p<=l && r<=q) return tree[atual];
        int mid=(l+r)/2;
        if(q<=mid) return query(2*atual,l,mid,p,q);
        if(p>mid) return query(2*atual+1,mid+1,r,p,q);
        return query(2*atual,l,mid,p,q)+query(2*atual+1,mid+1,r,p,q);
    }
};