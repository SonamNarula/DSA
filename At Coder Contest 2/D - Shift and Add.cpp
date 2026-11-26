#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DpState {
    int val;
    vector<pair<int, int>> pairs; // stores {sum, nines}
};

int ds[100000];

void init_ds() {
    for (int i = 0; i < 100000; i++) {
        int s = 0;
        int temp = i;
        while (temp > 0) {
            s += temp % 10;
            temp /= 10;
        }
        ds[i] = s;
    }
}

inline int get_digit_sum(int n) {
    return ds[n / 100000] + ds[n % 100000];
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<DpState> current_dp(512);
    current_dp[0].val = 0;
    current_dp[0].pairs = {{0, 0}};

    vector<DpState> next_dp(512);

    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < 512; mask++) {
            next_dp[mask].pairs.clear();
        }
        
        int a_val = a[i];
        int b_val = b[i];
        for (int mask = 0; mask < 512; mask++) {
            if (current_dp[mask].pairs.empty()) continue;
            
            int val = current_dp[mask].val;
            int sz = current_dp[mask].pairs.size();
            
            // Choice A
            {
                int next_mask = (mask << 1) & 511;
                long long temp = 10LL * val + a_val;
                int val_new = temp % 1000000000LL;
                int q = temp / 1000000000LL;
                
                next_dp[next_mask].val = val_new;
                for (int k = 0; k < sz; k++) {
                    auto& p = current_dp[mask].pairs[k];
                    int s_new = p.first;
                    int nines_new = 0;
                    if (q <= 9) {
                        s_new += q;
                        nines_new = (q == 9) ? p.second + 1 : 0;
                    } else { // q == 10
                        s_new = p.first - 9 * p.second + 1;
                        nines_new = 0;
                    }
                    next_dp[next_mask].pairs.push_back({s_new, nines_new});
                }
            }
            
            // Choice B
            {
                int next_mask = ((mask << 1) | 1) & 511;
                long long temp = 10LL * val + b_val;
                int val_new = temp % 1000000000LL;
                int q = temp / 1000000000LL;
                
                next_dp[next_mask].val = val_new;
                for (int k = 0; k < sz; k++) {
                    auto& p = current_dp[mask].pairs[k];
                    int s_new = p.first;
                    int nines_new = 0;
                    if (q <= 9) {
                        s_new += q;
                        nines_new = (q == 9) ? p.second + 1 : 0;
                    } else { // q == 10
                        s_new = p.first - 9 * p.second + 1;
                        nines_new = 0;
                    }
                    next_dp[next_mask].pairs.push_back({s_new, nines_new});
                }
            }
        }
        
        // Prune next_dp into current_dp
        for (int mask = 0; mask < 512; mask++) {
            if (next_dp[mask].pairs.empty()) {
                current_dp[mask].pairs.clear();
                continue;
            }
            
            current_dp[mask].val = next_dp[mask].val;
            
            // Sort next state pairs by sum (ascending), then by nines (descending)
            sort(next_dp[mask].pairs.begin(), next_dp[mask].pairs.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
                if (x.first != y.first) return x.first < y.first;
                return x.second > y.second;
            });
            
            // We prune directly into current_dp[mask].pairs
            current_dp[mask].pairs.clear();
            for (auto& p : next_dp[mask].pairs) {
                bool dominated = false;
                for (auto& kp : current_dp[mask].pairs) {
                    // Stronger pruning condition: p is dominated by kp if:
                    // kp.first <= p.first and (p.second <= kp.second or p.first - kp.first >= 9 * (p.second - kp.second))
                    if (kp.first <= p.first) {
                        if (p.second <= kp.second || p.first - kp.first >= 9 * (p.second - kp.second)) {
                            dominated = true;
                            break;
                        }
                    }
                }
                if (!dominated) {
                    current_dp[mask].pairs.push_back(p);
                }
            }
        }
        
        // Find answer for k = i
        int ans = 2e9;
        for (int mask = 0; mask < 512; mask++) {
            if (current_dp[mask].pairs.empty()) continue;
            int val = current_dp[mask].val;
            int ds_val = get_digit_sum(val);
            for (auto& p : current_dp[mask].pairs) {
                ans = min(ans, p.first + ds_val);
            }
        }
        cout << ans << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init_ds();
    solve();
    return 0;
}
