#include <iostream>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << "
";
        return;
    }
    if (n == 2) {
        cout << -1 << "
";
        return;
    }
    for (int i = n - 3; i >= 0; i--) {
        cout << 3LL * (1LL << i) << " ";
    }
    cout << "2 1
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