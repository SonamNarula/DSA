#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int D_OFFSET = 25;

void solve() {
    string s;
    int k;
    if (!(cin >> s >> k)) return;
    
    int n = s.length();
    vector<bool> is_orig(n + 3, false);
    for (int i = 0; i <= n - 3; i++) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            is_orig[i] = true;
        }
    }
    
    vector<int> dp((n + 5) * 50, INF);
    
    auto get_dp = [&](int idx, int d) {
        if (idx >= n) {
            return (d == 0) ? 0 : INF;
        }
        return dp[idx * 50 + d + D_OFFSET];
    };
    
    auto set_dp = [&](int idx, int d, int val) {
        dp[idx * 50 + d + D_OFFSET] = val;
    };
    
    for (int i = n - 1; i >= 0; i--) {
        for (int d = -20; d <= 15; d++) {
            int val = INF;
            
            if (is_orig[i]) {
                if (d + 1 <= 15) {
                    val = min(val, get_dp(i + 1, d + 1) + 1);
                }
            } else {
                val = min(val, get_dp(i + 1, d));
            }
            
            if (i + 3 <= n) {
                int cost = (s[i] != 'A') + (s[i+1] != 'B') + (s[i+2] != 'C');
                int c_orig = is_orig[i] + is_orig[i+1] + is_orig[i+2];
                int next_d = d - 1 + c_orig;
                if (next_d >= -20 && next_d <= 15) {
                    val = min(val, get_dp(i + 3, next_d) + cost);
                }
            }
            
            set_dp(i, d, val);
        }
    }
    
    int ans = get_dp(0, k);
    if (ans >= INF) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
