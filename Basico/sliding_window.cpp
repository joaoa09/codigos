// ==========================================
// 1. SLIDING WINDOW MEDIAN (O(N log K))
// ==========================================
multiset<int> menor,maior;
int k_janela; // Defina o tamanho da janela K antes de usar

void balancear(){
    int tam=(k_janela+1)/2;
    while(menor.size()>tam){
        maior.insert(*menor.rbegin());
        menor.erase(menor.find(*menor.rbegin()));
    }
    while(menor.size()<tam && !maior.empty()){
        menor.insert(*maior.begin());
        maior.erase(maior.find(*maior.begin()));
    }
}

void add(int x){
    if(menor.empty() || x<=*menor.rbegin()) menor.insert(x);
    else maior.insert(x);
    balancear();
}

void remover(int x){
    auto it=menor.find(x);
    if(it!=menor.end()) menor.erase(it);
    else maior.erase(maior.find(x));
    balancear();
}

int mediana(){
    return *menor.rbegin();
}


// ==========================================
// 2. SLIDING WINDOW SUM GENERICO (O(N))
// ==========================================
// Retorna a soma maxima de um subarray de tamanho K (Pode adaptar para soma minima, XOR, etc)
int sliding_window_sum(vector<int>& v,int k){
    
    int n=v.size();
    if(n<k) return 0; 
    
    int soma_atual=0;
    int max_soma=0; 

    // Calcula a primeira janela
    for(int i=0;i<k;i++){
        soma_atual+=v[i];
    }
    max_soma=soma_atual;

    // Desliza a janela subtraindo o que sai e somando o que entra
    for(int i=k;i<n;i++){
        soma_atual=soma_atual-v[i-k]+v[i];
        max_soma=max(max_soma,soma_atual);
    }
    
    return max_soma;
}