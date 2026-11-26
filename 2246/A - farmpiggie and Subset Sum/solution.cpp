#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            p[i] = i + 1;
        } else {
            p[i] = i - 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << "
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