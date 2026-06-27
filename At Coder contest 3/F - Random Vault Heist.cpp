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

struct Subset {
    long long val;
    int mask;
};

// Sort comparator by subset sum
bool compareSubsets(const Subset& a, const Subset& b) {
    return a.val < b.val;
}

vector<vector<Subset>> left_group;
vector<vector<Subset>> right_group;

int m1, m2;

void gen_left(int idx, long long curr_sum, int curr_sz, int mask, const vector<long long>& left) {
    if (idx == m1) {
        left_group[curr_sz].push_back({curr_sum, mask});
        return;
    }
    gen_left(idx + 1, curr_sum, curr_sz, mask, left);
    gen_left(idx + 1, curr_sum + left[idx], curr_sz + 1, mask | (1 << idx), left);
}

void gen_right(int idx, long long curr_sum, int curr_sz, int mask, const vector<long long>& right) {
    if (idx == m2) {
        right_group[curr_sz].push_back({curr_sum, mask});
        return;
    }
    gen_right(idx + 1, curr_sum, curr_sz, mask, right);
    gen_right(idx + 1, curr_sum + right[idx], curr_sz + 1, mask | (1 << idx), right);
}

vector<vector<long long>> filtered_left;
vector<vector<long long>> filtered_right;

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

        m1 = n / 2;
        m2 = n - m1;

        vector<long long> left(m1), right(m2);
        for (int i = 0; i < m1; i++) left[i] = a[i];
        for (int i = 0; i < m2; i++) right[i] = a[m1 + i];

        left_group.assign(m1 + 1, vector<Subset>());
        right_group.assign(m2 + 1, vector<Subset>());

        gen_left(0, 0, 0, 0, left);
        gen_right(0, 0, 0, 0, right);

        for (int s = 0; s <= m1; s++) {
            sort(left_group[s].begin(), left_group[s].end(), compareSubsets);
        }
        for (int s = 0; s <= m2; s++) {
            sort(right_group[s].begin(), right_group[s].end(), compareSubsets);
        }

        filtered_left.assign(m1 + 1, vector<long long>());
        filtered_right.assign(m2 + 1, vector<long long>());

        long long total_expected = 0;

        for (int v = 0; v < n; v++) {
            for (int s1 = 0; s1 <= m1; s1++) {
                filtered_left[s1].clear();
                filtered_left[s1].reserve(left_group[s1].size());
            }
            for (int s2 = 0; s2 <= m2; s2++) {
                filtered_right[s2].clear();
                filtered_right[s2].reserve(right_group[s2].size());
            }

            if (v < m1) {
                // v is in left. Filter left_group, right is unfiltered
                for (int s1 = 0; s1 <= m1; s1++) {
                    for (const auto& item : left_group[s1]) {
                        if (!(item.mask & (1 << v))) {
                            filtered_left[s1].push_back(item.val);
                        }
                    }
                }
                for (int s2 = 0; s2 <= m2; s2++) {
                    for (const auto& item : right_group[s2]) {
                        filtered_right[s2].push_back(item.val);
                    }
                }
            } else {
                // v is in right. Left is unfiltered, right is filtered
                int v_right = v - m1;
                for (int s1 = 0; s1 <= m1; s1++) {
                    for (const auto& item : left_group[s1]) {
                        filtered_left[s1].push_back(item.val);
                    }
                }
                for (int s2 = 0; s2 <= m2; s2++) {
                    for (const auto& item : right_group[s2]) {
                        if (!(item.mask & (1 << v_right))) {
                            filtered_right[s2].push_back(item.val);
                        }
                    }
                }
            }

            vector<long long> ways(n + 1, 0);

            for (int s1 = 0; s1 <= m1; s1++) {
                for (int s2 = 0; s2 <= m2; s2++) {
                    int k = s1 + s2;
                    const auto& l_list = filtered_left[s1];
                    const auto& r_list = filtered_right[s2];

                    if (l_list.empty() || r_list.empty()) continue;

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
