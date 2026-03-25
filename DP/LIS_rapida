#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 200010;

int arr[MAXN];
int lis[MAXN];      // lis[i] = menor valor final possivel para uma LIS de tamanho i+1
int pos_lis[MAXN];  // pos_lis[i] = indice no 'arr' do cara que ta no lis[i]
int pai[MAXN];      // pai[i] = de qual indice o arr[i] veio

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){

        cin >> arr[i];
    }

    int sz = 0;          // Tamanho atual da LIS
    int ultimo_idx = -1; // Indice no 'arr' de onde a LIS maxima termina

    for(int i = 0; i < N; i++){

        // lower_bound acha o primeiro elemento >= arr[i]. 
        // DICA: Se a questao pedir "Nao-decrescente" (permitir iguais), mude para upper_bound!
        int pos = lower_bound(lis, lis + sz, arr[i]) - lis;

        lis[pos] = arr[i];
        pos_lis[pos] = i;

        // Se nao for o primeiro elemento da sequencia, ele tem um pai
        if(pos > 0){

            pai[i] = pos_lis[pos - 1]; 
        } 
        else {

            pai[i] = -1; // -1 significa que ele comeca a sequencia
        }

        // Se ele entrou na ultima posicao, a LIS cresceu
        if(pos == sz){

            sz++; 
        }

        // Sempre que alguem atualizar a ultima posicao valida, ele eh o novo fim da LIS
        if(pos == sz - 1){

            ultimo_idx = i; 
        }
    }

    cout << sz << '\n';

    // --- RECONSTRUCAO ---
    vector<int> sequencia;
    int atual = ultimo_idx;

    while(atual != -1){

        sequencia.push_back(arr[atual]);
        atual = pai[atual];
    }

    // Inverte porque viemos do fim pro comeco
    reverse(sequencia.begin(), sequencia.end());

    for(int x : sequencia){

        cout << x << " ";
    }
    cout << '\n';

    return 0;
}