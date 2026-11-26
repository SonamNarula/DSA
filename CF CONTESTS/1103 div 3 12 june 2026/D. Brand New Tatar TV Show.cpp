#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to store a DP state
struct State {
    int val;
    int sum;
    int nines;

    bool operator<(const State& other) const {
        if (val != other.val) return val < other.val;
        if (sum != other.sum) return sum < other.sum;
        return nines > other.nines;
    }
};

// Helper function to calculate digit sum of a value < 10^9
int get_digit_sum(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<State> states = {{0, 0, 0}};

    for (int i = 1; i <= n; i++) {
        vector<State> next_states;
        next_states.reserve(states.size() * 2);

        int choices[2] = {a[i], b[i]};
        for (const auto& s : states) {
            for (int c : choices) {
                long long temp = 10LL * s.val + c;
                int val_new = temp % 1000000000LL;
                int q = temp / 1000000000LL;

                int s_new = s.sum;
                int nines_new = 0;
                if (q <= 9) {
                    s_new += q;
                    nines_new = (q == 9) ? s.nines + 1 : 0;
                } else { // q == 10
                    s_new = s.sum - 9 * s.nines + 1;
                    nines_new = 0;
                }
                next_states.push_back({val_new, s_new, nines_new});
            }
        }

        // Sort next_states by val, sum (ascending), and nines (descending)
        sort(next_states.begin(), next_states.end());

        // Group by val and prune dominated states
        states.clear();
        int sz = next_states.size();
        int idx = 0;
        while (idx < sz) {
            int end_idx = idx;
            while (end_idx < sz && next_states[end_idx].val == next_states[idx].val) {
                end_idx++;
            }

            // Prune the group [idx, end_idx - 1]
            vector<pair<int, int>> kept;
            for (int k = idx; k < end_idx; k++) {
                int s = next_states[k].sum;
                int n = next_states[k].nines;
                bool dominated = false;
                for (const auto& p : kept) {
                    if (p.first <= s && p.second >= n) {
                        dominated = true;
                        break;
                    }
                }
                if (!dominated) {
                    kept.push_back({s, n});
                    states.push_back({next_states[idx].val, s, n});
                }
            }
            idx = end_idx;
        }

        // Compute the answer for k = i
        int ans = 2e9;
        for (const auto& s : states) {
            ans = min(ans, s.sum + get_digit_sum(s.val));
        }
        cout << ans << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
