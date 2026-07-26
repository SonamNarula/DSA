#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    if (k == n - 1) {
        cout << "-1
";
        return;
    }
 
    int b = n - k;
    int o = (b + 1) / 2;
    int e = b / 2;
 
    int n0 = (n + 1) / 2;
    int n1 = n / 2;
    if (n0 >= o && n1 >= e) {
        string ans = "";
        vector<int> x(b, 1);
        x[0] += (n0 - o);
        x[1] += (n1 - e);
        for (int i = 0; i < b; ++i) {
            char c = (i % 2 == 0) ? '0' : '1';
            ans += string(x[i], c);
        }
        cout << ans << "
";
        return;
    }
 
    n0 = n / 2;
    n1 = (n + 1) / 2;
    if (n1 >= o && n0 >= e) {
        string ans = "";
        vector<int> x(b, 1);
        x[0] += (n1 - o);
        x[1] += (n0 - e);
        for (int i = 0; i < b; ++i) {
            char c = (i % 2 == 0) ? '1' : '0';
            ans += string(x[i], c);
        }
        cout << ans << "
";
        return;
    }
 
    cout << "-1
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