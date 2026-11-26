#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int G = 3;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void ntt(vector<int>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = power(G, (MOD - 1) / len);
        if (invert) wlen = modInverse(wlen);
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = (u + v < MOD ? u + v : u + v - MOD);
                a[i + j + len / 2] = (u - v >= 0 ? u - v : u - v + MOD);
                w = (w * wlen) % MOD;
            }
        }
    }
    if (invert) {
        long long n_inv = modInverse(n);
        for (int& x : a) {
            x = (x * n_inv) % MOD;
        }
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n, 0);
    fb.resize(n, 0);
    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; i++) {
        fa[i] = (1LL * fa[i] * fb[i]) % MOD;
    }
    ntt(fa, true);
    while (fa.size() > 1 && fa.back() == 0) {
        fa.pop_back();
    }
    return fa;
}

struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a.size() > b.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        vector<int> c(n);
        vector<int> g(n);
        vector<int> b_count(n + 1, 0);
        vector<int> p_count(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            b_count[c[i]]++;
        }
        for (int i = 0; i < n; i++) {
            cin >> g[i];
            p_count[g[i]]++;
        }
        
        vector<long long> fact(n + 1, 1);
        vector<long long> invFact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[n] = modInverse(fact[n]);
        for (int i = n - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
        
        auto nCr = [&](int n_val, int r_val) {
            if (r_val < 0 || r_val > n_val) return 0LL;
            return fact[n_val] * invFact[r_val] % MOD * invFact[n_val - r_val] % MOD;
        };
        
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        
        for (int col = 1; col <= n; col++) {
            int m_val = min(b_count[col], p_count[col]);
            if (m_val == 0) continue;
            
            vector<int> poly(m_val + 1);
            for (int j = 0; j <= m_val; j++) {
                long long term = nCr(p_count[col], j) * nCr(b_count[col], j) % MOD * fact[j] % MOD;
                if (j % 2 == 1) {
                    term = (MOD - term) % MOD;
                }
                poly[j] = term;
            }
            pq.push(poly);
        }
        
        vector<int> H = {1};
        while (!pq.empty()) {
            if (pq.size() == 1) {
                H = pq.top();
                pq.pop();
            } else {
                vector<int> poly1 = pq.top();
                pq.pop();
                vector<int> poly2 = pq.top();
                pq.pop();
                pq.push(multiply(poly1, poly2));
            }
        }
        
        long long total_ways = 0;
        for (int j = 0; j < H.size(); j++) {
            long long term = 1LL * H[j] * fact[n - j] % MOD;
            total_ways = (total_ways + term) % MOD;
        }
        
        long long ans = total_ways * modInverse(fact[n]) % MOD;
        cout << ans << "\n";
    }
    
    return 0;
}
