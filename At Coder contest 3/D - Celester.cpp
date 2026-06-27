#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<long long> y(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> y[i];
    }

    long long dp_s;
    long long dp_r;

    if (s[0] == 'S') {
        dp_s = 0;
        dp_r = -x[0];
    } else {
        dp_s = -x[0];
        dp_r = 0;
    }

    for (int i = 1; i < n; i++) {
        long long cost_s;
        long long cost_r;

        if (s[i] == 'S') {
            cost_s = 0;
            cost_r = x[i];
        } else {
            cost_s = x[i];
            cost_r = 0;
        }

        long long next_dp_s = max(dp_s, dp_r + y[i - 1]) - cost_s;
        long long next_dp_r = max(dp_s, dp_r) - cost_r;

        dp_s = next_dp_s;
        dp_r = next_dp_r;
    }

    long long ans = max(dp_s, dp_r);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
