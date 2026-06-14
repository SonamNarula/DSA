#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

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

void fwht(vector<long long>& a) {
    int n = a.size();
    for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                long long u = a[i + j];
                long long v = a[i + len + j];
                a[i + j] = (u + v) % MOD;
                a[i + len + j] = (u - v + MOD) % MOD;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    int num_vals = 1 << m;
    vector<int> cnt(num_vals, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<vector<int>> val_by_cnt(n + 1);
    for (int Y = 0; Y < num_vals; Y++) {
        if (cnt[Y] > 0) {
            val_by_cnt[cnt[Y]].push_back(Y);
        }
    }

    vector<int> unique_counts;
    for (int u = 1; u <= n; u++) {
        if (!val_by_cnt[u].empty()) {
            unique_counts.push_back(u);
        }
    }

    int U = unique_counts.size();
    vector<int> active_list;
    vector<long long> sum_T(num_vals, 0);
    vector<long long> g(num_vals, 0);

    int B = 4500;
    bool has_fwht = false;

    // Process from U-1 down to 0
    for (int d = U - 1; d >= 0; d--) {
        int u_d = unique_counts[d];
        int u_prev = (d == 0) ? 0 : unique_counts[d - 1];
        long long weight = u_d - u_prev;

        for (int Y : val_by_cnt[u_d]) {
            active_list.push_back(Y);
        }

        int sz = active_list.size();
        if (sz <= B) {
            // Direct convolution
            for (int j = 0; j < sz; j++) {
                int y1 = active_list[j];
                g[0] = (g[0] + weight) % MOD;
                for (int k = j + 1; k < sz; k++) {
                    int y2 = active_list[k];
                    int x = y1 ^ y2;
                    g[x] = (g[x] + 2LL * weight) % MOD;
                }
            }
        } else {
            // FWHT accumulation
            has_fwht = true;
            vector<long long> S_vec(num_vals, 0);
            for (int Y : active_list) {
                S_vec[Y] = 1;
            }
            fwht(S_vec);
            for (int i = 0; i < num_vals; i++) {
                sum_T[i] = (sum_T[i] + S_vec[i] * S_vec[i] % MOD * weight) % MOD;
            }
        }
    }

    if (has_fwht) {
        fwht(sum_T);
        long long inv_n = power(num_vals, MOD - 2);
        for (int i = 0; i < num_vals; i++) {
            long long val = sum_T[i] * inv_n % MOD;
            g[i] = (g[i] + val) % MOD;
        }
    }

    // Now compute f(X) and output the sum
    long long ans = 0;
    
    // f(0)
    long long f0 = 0;
    for (int Y = 0; Y < num_vals; Y++) {
        f0 += cnt[Y] / 2;
    }
    f0 %= MOD;
    ans = (ans + f0) % MOD;

    // f(X) for X > 0
    long long inv_2 = power(2, MOD - 2);
    long long pow10 = 1;
    for (int X = 1; X < num_vals; X++) {
        pow10 = pow10 * 10 % MOD;
        long long fX = g[X] * inv_2 % MOD;
        ans = (ans + fX * pow10) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
