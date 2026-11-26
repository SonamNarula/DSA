#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> l(n), r(n), u(n), v(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i] >> u[i] >> v[i];
    }
 
    for (int m = n; m >= 1; --m) {
        int cur = 0;
        bool ok = true;
        for (int j = 1; j <= m; ++j) {
            bool found = false;
            while (cur < n) {
                int i = cur++;
                if ((j < l[i] || j > r[i]) && (m - j + 1 < u[i] || m - j + 1 > v[i])) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << m << "
";
            return;
        }
    }
    cout << 0 << "
";
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