// Prefix Function
//
// pi[i] = tamanho da maior borda de s[0..i]
// borda é um prefixo que também é um sufixo da string
//
//Complexidade:
// O(n)

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}