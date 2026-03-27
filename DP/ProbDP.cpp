// ==========================================
// PROBABILITY DP - TEMPLATE E EXPLICACOES
// ==========================================
// dp[tempo][estado] armazena a probabilidade de estar num estado 'j' no tempo 'i'
// Regra: A soma de cada linha (tempo t) deve ser sempre 1.0 (100%)
double dp[105][1005]; 

void solve_probability(int T, int N, double p_sucesso, double p_falha) {
    
    // 1. Reset da DP: Garante que estados nao visitados tenham prob 0.0
    for(int i=0; i<=T; i++)
        for(int j=0; j<=N; j++) dp[i][j] = 0.0;

    // 2. Caso Base: No tempo 0, a chance de estar no inicio e 1.0 (100%)
    int inicio = 1; 
    dp[0][inicio] = 1.0;

    // 3. Transicoes: A probabilidade "flui" do tempo t para o tempo t+1
    for(int t=0; t<T; t++) {
        for(int pos=0; pos<=N; pos++) {
            
            if(dp[t][pos] > 0) { // Otimizacao: so processa estados alcancaveis
                
                // Exemplo: Sucesso move para frente, Falha mantem no lugar
                // Probabilidade acumulada = (Prob de estar aqui) * (Prob da acao)
                dp[t+1][pos+1] += dp[t][pos] * p_sucesso;
                dp[t+1][pos]   += dp[t][pos] * p_falha;
            }
        }
    }

    // 4. Resultados Comuns:
    // - Probabilidade exata: dp[T][destino]
    // - Valor Esperado (Expectancia): E = soma de (posicao * dp[T][posicao])
    double expectancia = 0;
    for(int j=0; j<=N; j++) {
        expectancia += (j * dp[T][j]);
    }
}

/* DICAS PARA O PDF:
   - Use 'long double' se o problema exigir precisao extrema.
   - Para economizar memoria: dp[2][MAXN] e use t%2 e (t+1)%2.
   - Se o tempo T for muito grande (ex: 10^9), use Exponenciacao de Matrizes.
   - SEMPRE use fixed << setprecision(10) no output.
*/