#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5 + 10;

int pai[MAXN];
int sz[MAXN];


vector<tuple<int, int, int>> arestas;

void init(int n) {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;  
        sz[i] = 1;  
    }
}

int find(int v) {
    if(pai[v] == v) return v;
    return pai[v] = find(pai[v]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(sz[b] > sz[a]) swap(a, b);

    pai[b] = a;
    sz[a] += sz[b];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    init(n);

    for(int i = 0; i < m; i++) {
        int u, v, peso;
        cin >> u >> v >> peso;
        arestas.push_back({peso, u, v});
    }

    sort(arestas.begin(), arestas.end());

    int custo_mst = 0;
    int arestas_usadas = 0;

    for(auto [peso, u, v] : arestas){

        if(find(u) != find(v)) {
            join(u, v);
            custo_mst += peso;
            arestas_usadas++;
        }
    }

    if(arestas_usadas == n - 1) {
        cout << custo_mst << "\n";
    } 
    else {
        cout << "IMPOSSIBLE\n"; 
    }

    return 0;
}
