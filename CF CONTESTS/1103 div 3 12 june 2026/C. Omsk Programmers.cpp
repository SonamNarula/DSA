#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1000000000000000000LL;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<vector<long long>> a(n + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    // cost[i][j] represents A_{i, j-1} + A_{i, j+1} (ignoring out-of-bounds)
    vector<vector<long long>> cost(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long long left_val = (j - 1 >= 1) ? a[i][j - 1] : 0;
            long long right_val = (j + 1 <= n) ? a[i][j + 1] : 0;
            cost[i][j] = left_val + right_val;
        }
    }
    
    // dp_down[i][j] stores the min cost of path from row 1 to row i ending at (i, j)
    vector<vector<long long>> dp_down(n + 2, vector<long long>(n + 2, INF));
    for (int j = 1; j <= n; j++) {
        dp_down[1][j] = cost[1][j];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long long prev_min = INF;
            if (j - 1 >= 1) prev_min = min(prev_min, dp_down[i - 1][j - 1]);
            if (j + 1 <= n) prev_min = min(prev_min, dp_down[i - 1][j + 1]);
            if (prev_min != INF) {
                dp_down[i][j] = cost[i][j] + prev_min;
            }
        }
    }
    
    // dp_up[i][j] stores the min cost of path from row n to row i ending at (i, j)
    vector<vector<long long>> dp_up(n + 2, vector<long long>(n + 2, INF));
    for (int j = 1; j <= n; j++) {
        dp_up[n][j] = cost[n][j];
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            long long next_min = INF;
            if (j - 1 >= 1) next_min = min(next_min, dp_up[i + 1][j - 1]);
            if (j + 1 <= n) next_min = min(next_min, dp_up[i + 1][j + 1]);
            if (next_min != INF) {
                dp_up[i][j] = cost[i][j] + next_min;
            }
        }
    }
    
    // min_cost[i][j] stores the min cost of path passing through (i, j)
    vector<vector<long long>> min_cost(n + 1, vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp_down[i][j] != INF && dp_up[i][j] != INF) {
                min_cost[i][j] = dp_down[i][j] + dp_up[i][j] - cost[i][j];
            }
        }
    }
    
    for (int h = 1; h <= n; h++) {
        for (int w = 1; w <= n; w++) {
            long long ans = INF;
            if (w - 1 >= 1) ans = min(ans, min_cost[h][w - 1]);
            if (w + 1 <= n) ans = min(ans, min_cost[h][w + 1]);
            cout << ans << (w == n ? "" : " ");
        }
        cout << "\n";
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
