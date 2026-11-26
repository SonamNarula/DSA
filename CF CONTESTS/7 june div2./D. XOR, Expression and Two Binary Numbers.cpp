#include <iostream>
#include <string>

using namespace std;

void solve() {
    long long n;
    int k;
    cin >> n >> k;

    string s, z;
    cin >> s >> z;

    long long left_only = 0, right_only = 0, both_one = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' && z[i] == '1') {
            ++both_one;
        } else if (s[i] == '1') {
            ++left_only;
        } else if (z[i] == '1') {
            ++right_only;
        }
    }

    long long cnt_left, cnt_right, cnt_xor;
    long long total = 1LL << k;
    if (k % 2 == 1) {
        cnt_left = cnt_right = cnt_xor = (total + 1) / 3;
    } else {
        cnt_left = cnt_right = (total + 2) / 3;
        cnt_xor = (total - 1) / 3;
    }

    long long ones_left = left_only + both_one;
    long long ones_right = right_only + both_one;
    long long ones_xor = left_only + right_only;

    long long ans = 0;
    ans += cnt_left * ones_left * (n - ones_left);
    ans += cnt_right * ones_right * (n - ones_right);
    ans += cnt_xor * ones_xor * (n - ones_xor);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
