// ==========================================
// 1. SWEEP LINE PARA QUERIES PONTUAIS (O((N+Q) log (N+Q)))
// ==========================================
// Conta quantos intervalos cobrem cada ponto de consulta (A)
void sweep_line_queries(vector<pair<int,int>>& intervalos,vector<int>& pontos_query){
    
    vector<pair<int,int>> eventos;
    for(auto p:intervalos){
        eventos.push_back({p.first,1});   // Inicio do intervalo
        eventos.push_back({p.second+1,-1}); // Fim do intervalo (aberto)
    }
    
    vector<pair<int,int>> qr;
    for(int i=0;i<pontos_query.size();i++){
        qr.push_back({pontos_query[i],i});
    }

    sort(eventos.begin(),eventos.end());
    sort(qr.begin(),qr.end());

    vector<int> resp(qr.size());
    int cur=0,indice=0;

    for(auto x:qr){
        while(indice<eventos.size() && eventos[indice].first<=x.first){
            cur+=eventos[indice].second;
            indice++;
        }
        resp[x.second]=cur;
    }
    for(int x:resp) cout<<x<<'\n';
}

// ==========================================
// 2. SWEEP LINE PARA COBERTURA TOTAL (O(M log M + N))
// ==========================================
// Conta quantos pontos de 1 a N estao cobertos por EXATAMENTE M intervalos
int sweep_line_total_coverage(int n_pontos,int m_intervalos,vector<pair<int,int>>& gates){
    
    vector<pair<int,int>> eventos;
    for(auto p:gates){
        eventos.push_back({p.first,1});
        eventos.push_back({p.second+1,-1});
    }

    sort(eventos.begin(),eventos.end());

    int counter=0,curr=0,indice=0;
    for(int i=1;i<=n_pontos;i++){
        while(indice<eventos.size() && eventos[indice].first<=i){
            curr+=eventos[indice].second;
            indice++;
        }
        if(curr==m_intervalos) counter++;
    }
    return counter;
}