#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

// Estrutura do No para Range Update e Range Max Query
struct Node {
    int mx = 0;
    int lazy = -1; // -1 indica que nao ha atualizacao pendente (assumindo valores >= 0)

    // Operacao de uniao (Merge) de dois nos
    Node operator + (const Node& a) const {
        Node resp;
        resp.mx = max(mx, a.mx);
        // O valor lazy NAO eh mesclado aqui. Ele eh tratado exclusivamente na funcao push()
        return resp;
    }
};

struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(int n) {
        this->n = n;
        tree.resize(4 * n + 5);
    }

    // Constroi a arvore a partir de um vector V (1-indexed)
    void build(int atual, int l, int r, const vector<int>& V) {
        if (l == r) {
            tree[atual].mx = V[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * atual, l, mid, V);
        build(2 * atual + 1, mid + 1, r, V);
        tree[atual] = tree[2 * atual] + tree[2 * atual + 1];
    }

    // Funcao para propagar o valor lazy para os filhos (o antigo void lazy())
    void push(int atual, int l, int r) {
        if (tree[atual].lazy == -1) return; // Nada a propagar

        // Aplica o efeito do lazy no no atual
        tree[atual].mx = tree[atual].lazy;

        // Se nao for folha, propaga a "preguica" para os filhos
        if (l != r) {
            tree[2 * atual].lazy = tree[atual].lazy;
            tree[2 * atual + 1].lazy = tree[atual].lazy;
        }

        // Limpa o lazy do no atual, pois ja foi processado
        tree[atual].lazy = -1;
    }

    // Atualizacao no intervalo [p, q] para um valor especifico (Assignment)
    void update(int atual, int l, int r, int p, int q, int valor) {
        push(atual, l, r); // Sempre propaga as pendencias antes de visitar o no

        if (r < p || l > q) return; // Totalmente fora

        if (p <= l && r <= q) {     // Totalmente dentro
            tree[atual].lazy = valor;
            push(atual, l, r);      // Aplica imediatamente e joga a responsabilidade pros filhos
            return;
        }

        int mid = (l + r) / 2;
        update(2 * atual, l, mid, p, q, valor);
        update(2 * atual + 1, mid + 1, r, p, q, valor);

        // Atualiza o no atual com base nos filhos ja atualizados
        tree[atual] = tree[2 * atual] + tree[2 * atual + 1];
    }

    // Consulta no intervalo [p, q] retornando um Node
    Node query(int atual, int l, int r, int p, int q) {
        push(atual, l, r); // Sempre propaga antes de ler a informacao

        if (r < p || l > q) {
            Node nulo; 
            nulo.mx = -INF; // Elemento neutro do MAX (nao vai afetar o resultado final)
            return nulo; 
        }

        if (p <= l && r <= q) return tree[atual];

        int mid = (l + r) / 2;
        Node esq = query(2 * atual, l, mid, p, q);
        Node dir = query(2 * atual + 1, mid + 1, r, p, q);

        return esq + dir; // Usa o operator+ que voce definiu na struct Node
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Q;
    if (!(cin >> n >> Q)) return 0;

    vector<int> v(n + 1, 0); // Opcional: Ler array inicial
    // for(int i=1; i<=n; i++) cin >> v[i];

    // Instanciando a SegTree
    SegTree seg(n);
    
    // Constrói a árvore (descomente se for iniciar com valores de v)
    // seg.build(1, 1, n, v);

    for (int i = 0; i < Q; i++) {
        int op;
        cin >> op;

        if (op == 1) { // Range Update (ex: atribuir `valor` a todos de p ate q)
            int p, q, valor;
            cin >> p >> q >> valor;
            p++; q++; // Convertendo para 1-indexed, se a entrada for 0-indexed (ajuste conforme o problema)
            
            seg.update(1, 1, n, p, q, valor);
        } 
        else { // Range Query
            int p, q;
            cin >> p >> q;
            p++; q++; // Convertendo para 1-indexed
            
            Node resp = seg.query(1, 1, n, p, q);
            cout << resp.mx << '\n';
        }
    }

    return 0;
}