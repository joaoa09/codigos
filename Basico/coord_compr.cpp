// ==========================================
// COMPRESSAO DE COORDENADAS (O(N log N))
// ==========================================
vector<int> coords;

// Adicione todos os valores que deseja comprimir antes de chamar build()
void add_coord(int x){
    coords.push_back(x);
}

// Prepara o mapeamento removendo duplicatas e ordenando
void build_comp(){
    sort(coords.begin(),coords.end());
    coords.erase(unique(coords.begin(),coords.end()),coords.end());
}

// Retorna o indice comprimido (1-indexed para facilitar na SegTree)
int get_id(int x){
    return lower_bound(coords.begin(),coords.end(),x)-coords.begin()+1;
}

// Retorna o valor original a partir do indice comprimido (1-indexed)
int get_val(int id){
    return coords[id-1];
}

// Retorna quantos valores unicos existem
int total_coords(){
    return coords.size();
}