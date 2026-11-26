#include <iostream>
 
using namespace std;
 
int get_g(int v, int x, int d) {
    int p = __builtin_ctz(x); // direct bit manipulation (count trailing zeros)
    int ans = 0;
    for (int k = 0; k < d; ++k) {
        if ((v >> k) & 1) {
            if (k == 1) ans ^= x;
            else if (k == p) ans ^= 2;
            else ans ^= (1 << k);
        }
    }
    return ans;
}
 
void solve() {
    int n, x;
    cin >> n >> x;
 
    if (n & (n - 1)) {
        cout << "-1
";
        return;
    }
 
    if (n == 2) {
        if (x == 0) cout << "0 1
1 0
";
        else cout << "-1
";
        return;
    }
 
    int d = __builtin_ctz(n);
 
    if (x == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << (i ^ j) << (j == n - 1 ? "" : " ");
            }
            cout << "
";
        }
        return;
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = i ^ j ^ ((i & j & 1) ? 2 : 0);
            cout << get_g(val, x, d) << (j == n - 1 ? "" : " ");
        }
        cout << "
";
    }
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