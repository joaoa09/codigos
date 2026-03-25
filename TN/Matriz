struct Matrix {
    vector<vector<int>> mat;
    int r, c;

    Matrix(int r, int c) : r(r), c(c) {
        mat.assign(r, vector<int>(c, 0));
    }

    // Retorna a matriz Identidade (1 na diagonal, 0 no resto)
    static Matrix identity(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; i++) res.mat[i][i] = 1;
        return res;
    }

    Matrix operator*(const Matrix& o) const {
        Matrix res(r, o.c);
        for (int i = 0; i < r; i++)
            for (int k = 0; k < c; k++) {
                if (mat[i][k] == 0) continue; // Otimizacao para matrizes esparsas
                for (int j = 0; j < o.c; j++)
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * o.mat[k][j]) % MOD;
            }
        return res;
    }
};

// Eleva a matriz a potencia 'exp' em O(K^3 log exp)
Matrix matrix_pow(Matrix base, int exp) {
    Matrix res = Matrix::identity(base.r);
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base;
        base = base * base;
        exp /= 2;
    }
    return res;
}

/* COMO USAR NA PRATICA (EXEMPLO FIBONACCI):
   1. Defina o estado inicial: V1 = [F1=1, F0=0]
   2. Monte a matriz de transicao T = [[1, 1], [1, 0]]
   3. Para achar o Fn, calcule T^(n-1) * V1.
   
   No codigo:
   Matrix T(2, 2);
   T.mat = {{1, 1}, {1, 0}};
   T = matrix_pow(T, n - 1);
   int res = (T.mat[0][0] * 1 + T.mat[0][1] * 0) % MOD;
*/