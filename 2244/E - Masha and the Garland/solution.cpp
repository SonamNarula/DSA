#include <iostream>
#include <string>
 
using namespace std;
 
int p[200005];
 
void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    string s;
    cin >> s;
    
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1];
        if (s[i - 1] == s[i]) {
            p[i]++;
        }
    }
    
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        if (l == r) {
            cout << "YES
";
            continue;
        }
        int dup = p[r - 1] - p[l - 1];
        if (dup <= 2 * k) {
            cout << "YES
";
        } else {
            cout << "NO
";
        }
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