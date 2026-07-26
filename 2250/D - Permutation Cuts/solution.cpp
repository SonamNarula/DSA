#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int MOD = 998244353;
const int MAXN = 1000005;
 
// Global arrays - classic CP style for maximum speed
int a[MAXN];
int val_len[MAXN];
bool seen[MAXN];
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }
 
    vector<int> vals;
    vector<int> lens;
    
    // Simple compression loop
    for (int i = 0; i < n - 1; ) {
        int val = a[i];
        int len = 0;
        while (i < n - 1 && a[i] == val) {
            len++;
            i++;
        }
        vals.push_back(val);
        lens.push_back(len);
    }
 
    int sz = vals.size();
    
    // Reset global arrays for the current test case
    for (int i = 0; i <= n; ++i) {
        seen[i] = false;
        val_len[i] = 0;
    }
 
    // Check if distinct
    for (int i = 0; i < sz; ++i) {
        int v = vals[i];
        if (v < 1 || v > n || seen[v]) {
            cout << 0 << "
";
            return;
        }
        seen[v] = true;
    }
 
    int max_val = -1;
    int peak = -1;
    for (int i = 0; i < sz; ++i) {
        if (vals[i] > max_val) {
            max_val = vals[i];
            peak = i;
        }
    }
 
    if (max_val != n - 1) {
        cout << 0 << "
";
        return;
    }
 
    // Check unimodal properties
    for (int i = 0; i < peak; ++i) {
        if (vals[i] >= vals[i + 1]) {
            cout << 0 << "
";
            return;
        }
    }
    for (int i = peak; i < sz - 1; ++i) {
        if (vals[i] <= vals[i + 1]) {
            cout << 0 << "
";
            return;
        }
    }
 
    for (int i = 0; i < sz; ++i) {
        val_len[vals[i]] = lens[i];
    }
 
    long long ans = 1;
    long long cnt = 0;
    for (int x = n - 1; x >= 1; --x) {
        if (val_len[x] > 0) {
            cnt += val_len[x] - 1;
        } else {
            ans = (ans * cnt) % MOD;
            cnt--;
            if (cnt < 0) {
                cout << 0 << "
";
                return;
            }
        }
    }
 
    cout << (2 * ans) % MOD << "
";
}
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}