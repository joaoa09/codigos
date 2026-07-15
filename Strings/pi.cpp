// Prefix Function e KMP
//
// pi[i] = tamanho da maior borda de s[0..i]
// borda é um prefixo que também é um sufixo da string
// KMP armazena os matches da string com o padrão
//
// Complexidades:
// pi: O(n)
// KMP: O(n+m)

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

vector<int> kmp_match(string pat, string text) {
    vector<int> pi = prefix_function(pat);
    vector<int> occ;

    int j = 0;

    for (int i = 0; i < (int)text.size(); i++) {
        while (j > 0 && text[i] != pat[j]) {
            j = pi[j - 1];
        }

        if (text[i] == pat[j]) {
            j++;
        }

        if (j == (int)pat.size()) {
            occ.push_back(i - j + 1);
            j = pi[j - 1];
        }
    }

    return occ;
}