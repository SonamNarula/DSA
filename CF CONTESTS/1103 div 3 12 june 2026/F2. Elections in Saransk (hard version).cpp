#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_A = 500000;
int spf[MAX_A + 1];

// Precompute smallest prime factor (SPF) for all numbers up to MAX_A
void sieve() {
    for (int i = 1; i <= MAX_A; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAX_A; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAX_A; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

// Global arrays for tracking exponent sums and lists of exponents for each prime
int sum_exp[MAX_A + 1];
vector<int> exps[MAX_A + 1];
vector<int> modified;

// DP solver to count valid exponent assignments when K > 0
long long solve_dp_with_K(const vector<int>& L, int K) {
    int m = L.size();
    long long MOD = 1000000007;
    long long total_ways = 0;
    
    // Helper lambda to compute subset sum DP to target S with elements capped at C
    // Optimized to run in O(target) per element using prefix sums
    auto get_subset_sum = [&](<int C, int target>) -> long long {
        if (target < 0) return 0;
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int x_val : L) {
            int limit = min(x_val, C);
            vector<long long> psum(target + 1, 0);
            psum[0] = dp[0];
            for (int s = 1; s <= target; s++) {
                psum[s] = (psum[s - 1] + dp[s]) % MOD;
            }
            for (int s = 0; s <= target; s++) {
                long long val = psum[s];
                if (s - limit - 1 >= 0) {
                    val = (val - psum[s - limit - 1] + MOD) % MOD;
                }
                dp[s] = val;
            }
        }
        return dp[target];
    };
    
    // Case 1: The maximum element M satisfies M <= K
    for (int M = 0; M <= K; M++) {
        long long ways_le = get_subset_sum(M, K + M);
        long long ways_lt = (M > 0) ? get_subset_sum(M - 1, K + M) : 0;
        long long ways_eq = (ways_le - ways_lt + MOD) % MOD;
        total_ways = (total_ways + ways_eq) % MOD;
    }
    
    // Case 2: The maximum element M satisfies M > K (unique maximum at index j)
    // We compute prefix and suffix DPs to calculate target sum K excluding index j
    vector<vector<long long>> pref(m + 1, vector<long long>(K + 1, 0));
    pref[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        int limit = min(L[i - 1], K);
        vector<long long> psum(K + 1, 0);
        psum[0] = pref[i - 1][0];
        for (int s = 1; s <= K; s++) psum[s] = (psum[s - 1] + pref[i - 1][s]) % MOD;
        for (int s = 0; s <= K; s++) {
            long long val = psum[s];
            if (s - limit - 1 >= 0) val = (val - psum[s - limit - 1] + MOD) % MOD;
            pref[i][s] = val;
        }
    }
    
    vector<vector<long long>> suff(m + 2, vector<long long>(K + 1, 0));
    suff[m + 1][0] = 1;
    for (int i = m; i >= 1; i--) {
        int limit = min(L[i - 1], K);
        vector<long long> psum(K + 1, 0);
        psum[0] = suff[i + 1][0];
        for (int s = 1; s <= K; s++) psum[s] = (psum[s - 1] + suff[i + 1][s]) % MOD;
        for (int s = 0; s <= K; s++) {
            long long val = psum[s];
            if (s - limit - 1 >= 0) val = (val - psum[s - limit - 1] + MOD) % MOD;
            suff[i][s] = val;
        }
    }
    
    for (int j = 1; j <= m; j++) {
        long long choices = max(0, L[j - 1] - K);
        if (choices == 0) continue;
        
        long long ways_other = 0;
        for (int s = 0; s <= K; s++) {
            long long term = (pref[j - 1][s] * suff[j + 1][K - s]) % MOD;
            ways_other = (ways_other + term) % MOD;
        }
        total_ways = (total_ways + choices * ways_other) % MOD;
    }
    
    return total_ways;
}

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> x_primes;
    vector<int> v_x(MAX_A + 1, 0);
    
    // Factorize x to find relevant primes where K > 0
    int temp_x = x;
    while (temp_x > 1) {
        int p = spf[temp_x];
        int cnt = 0;
        while (temp_x % p == 0) {
            cnt++;
            temp_x /= p;
        }
        x_primes.push_back(p);
        v_x[p] = cnt;
    }
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        
        while (val > 1) {
            int p = spf[val];
            int cnt = 0;
            while (val % p == 0) {
                cnt++;
                val /= p;
            }
            if (v_x[p] > 0) {
                exps[p].push_back(cnt);
            } else {
                if (sum_exp[p] == 0) {
                    modified.push_back(p);
                }
                sum_exp[p] += cnt;
            }
        }
    }
    
    long long ans = 1;
    long long MOD = 1000000007;
    
    // Process primes that do not divide x (K = 0)
    for (int p : modified) {
        long long choices = (1 + sum_exp[p]) % MOD;
        ans = (ans * choices) % MOD;
        sum_exp[p] = 0; // Reset
    }
    modified.clear();
    
    // Process primes that divide x (K > 0) using DP
    for (int p : x_primes) {
        long long choices = solve_dp_with_K(exps[p], v_x[p]);
        ans = (ans * choices) % MOD;
        exps[p].clear(); // Reset
        v_x[p] = 0; // Reset
    }
    x_primes.clear();
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
