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

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// Precompute combinations modulo MOD using Pascal's triangle
long long C[50][50];
void precompute_comb() {
    for (int i = 0; i < 50; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

// Helper vectors for subset sum generation
vector<vector<long long>> left_sums;
vector<vector<long long>> right_sums;

void gen_left(int idx, long long curr_sum, int curr_sz, const vector<long long>& left) {
    if (idx == left.size()) {
        left_sums[curr_sz].push_back(curr_sum);
        return;
    }
    gen_left(idx + 1, curr_sum, curr_sz, left);
    gen_left(idx + 1, curr_sum + left[idx], curr_sz + 1, left);
}

void gen_right(int idx, long long curr_sum, int curr_sz, const vector<long long>& right) {
    if (idx == right.size()) {
        right_sums[curr_sz].push_back(curr_sum);
        return;
    }
    gen_right(idx + 1, curr_sum, curr_sz, right);
    gen_right(idx + 1, curr_sum + right[idx], curr_sz + 1, right);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_comb();

    int n;
    long long x;
    if (cin >> n >> x) {
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long total_expected = 0;

        for (int v = 0; v < n; v++) {
            vector<long long> rem;
            for (int i = 0; i < n; i++) {
                if (i != v) rem.push_back(a[i]);
            }

            int m = rem.size();
            vector<long long> left, right;
            for (int i = 0; i < m / 2; i++) {
                left.push_back(rem[i]);
            }
            for (int i = m / 2; i < m; i++) {
                right.push_back(rem[i]);
            }

            left_sums.assign(left.size() + 1, vector<long long>());
            right_sums.assign(right.size() + 1, vector<long long>());

            gen_left(0, 0, 0, left);
            gen_right(0, 0, 0, right);

            for (int s = 0; s <= left.size(); s++) {
                sort(left_sums[s].begin(), left_sums[s].end());
            }
            for (int s = 0; s <= right.size(); s++) {
                sort(right_sums[s].begin(), right_sums[s].end());
            }

            vector<long long> ways(n, 0);

            for (int s1 = 0; s1 <= left.size(); s1++) {
                for (int s2 = 0; s2 <= right.size(); s2++) {
                    int k = s1 + s2;
                    const auto& l_list = left_sums[s1];
                    const auto& r_list = right_sums[s2];

                    int j = (int)r_list.size() - 1;
                    for (int i = 0; i < l_list.size(); i++) {
                        while (j >= 0 && l_list[i] + r_list[j] >= x) {
                            j--;
                        }
                        ways[k] += (j + 1);
                    }
                }
            }

            long long p_v = 0;
            for (int k = 0; k < n; k++) {
                long long denom = (1LL * n * C[n - 1][k]) % MOD;
                long long weight = modInverse(denom);
                long long term = (ways[k] % MOD) * weight % MOD;
                p_v = (p_v + term) % MOD;
            }

            long long term = (a[v] % MOD) * p_v % MOD;
            total_expected = (total_expected + term) % MOD;
        }

        cout << total_expected << "\n";
    }

    return 0;
}
