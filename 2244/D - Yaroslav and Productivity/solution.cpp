#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }
    
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
 
    long long ans = 0;
    int last = 0;
    for (int i = 0; i < m; i++) {
        long long cur_sum = pref[b[i]] - pref[last];
        if (cur_sum < 0) {
            cur_sum = -cur_sum;
        }
        ans += cur_sum;
        last = b[i];
    }
    
    if (last < n) {
        ans += pref[n] - pref[last];
    }
    cout << ans << "
";
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