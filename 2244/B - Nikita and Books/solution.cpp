#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    long long sum = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
        long long req = (long long)(i + 1) * (i + 2) / 2;
        if (sum < req) {
            ok = false;
        }
    }
    if (ok) {
        cout << "YES
";
    } else {
        cout << "NO
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