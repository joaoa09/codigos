//Suffix Array and LCP (Kasai)
//
//lcp[i]=LCP(sa[i],sa[i+1])
//lcp[n-1]=0
//
//suffix_array O(nlog(n))
//kasai O(n)

vector<int> suffix_array(string s) {
    s += '!';
    int n = s.size();
    vector<int> sa(n), rnk(n), tmp(n), cnt(n);

    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int i, int j) { return s[i] < s[j]; });

    for (int i = 1, c = 0; i < n; i++) {
        rnk[sa[i]] = c += s[sa[i]] != s[sa[i - 1]];
    }

    for (int k = 1; rnk[sa[n - 1]] < n - 1; k <<= 1) {
        cnt.assign(n, 0);

        for (int& x : sa) x = (x - k + n) % n, cnt[rnk[x]]++;
        for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) tmp[--cnt[rnk[sa[i]]]] = sa[i];

        sa.swap(tmp);

        tmp[sa[0]] = 0;
        for (int i = 1, c = 0; i < n; i++) {
            pair<int, int> a = {rnk[sa[i]], rnk[(sa[i] + k) % n]};
            pair<int, int> b = {rnk[sa[i - 1]], rnk[(sa[i - 1] + k) % n]};
            tmp[sa[i]] = c += a != b;
        }

        rnk.swap(tmp);
    }
    return vector<int>(sa.begin() + 1, sa.end());
}

vector<int> kasai(const string& s, const vector<int>& sa) {
    int n = s.size(), k = 0;
    vector<int> rnk(n), lcp(n, 0);

    for (int i = 0; i < n; i++) rnk[sa[i]] = i;

    for (int i = 0; i < n; i++, k -= !!k) {
        if (rnk[i] == n - 1) {
            k = 0;
            continue;
        }

        int j = sa[rnk[i] + 1];

        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;

        lcp[rnk[i]] = k;
    }

    return lcp;
}