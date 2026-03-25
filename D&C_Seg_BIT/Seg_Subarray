#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;

int n;

class Node{
public:

    int soma=0, mpref=0, msuf=0, ans=0;

    Node operator + (Node a){

        Node resp;

        resp.soma=soma+a.soma;

        resp.mpref=max(mpref,soma+a.mpref);

        resp.msuf=max(a.msuf,msuf+a.soma);

        resp.ans=max({ans,a.ans,msuf+a.mpref});
      
        return resp;

    }
};

vector<Node> tree;
vector<int> V;


void build(int atual, int l, int r){
    if(l==r){

        tree[atual].soma=V[l];
        tree[atual].mpref=tree[atual].msuf=tree[atual].ans=max(0LL,V[l]);
        return;
    }

    int mid=(l+r)/2;

    build(2*atual, l, mid);
    build(2*atual+1, mid+1, r);

    tree[atual]=tree[2*atual]+tree[2*atual+1];
}

void query(int atual, int l, int r, int p, int q, Node &resp){
    if(r<p || l>q)return;
    if(p<=l && r<=q){
        resp=resp+tree[atual];
        return;
    }

    int mid=(l+r)/2;
    query(2*atual, l, mid, p, q, resp);
    query(2*atual+1, mid+1, r, p, q, resp);
}


int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int t;
    cin >> t;

    V.resize(n+1);

    for(int i=1; i<=n; i++){
        cin >> V[i];
    }

    tree.resize(4*n);
    build(1, 1, n);

    for(int i=0; i<t; i++){

            int p, q;
            cin >> p >> q;
            Node resp;

            query(1, 1, n, p, q, resp);

            cout << resp.ans << '\n';
        }

}