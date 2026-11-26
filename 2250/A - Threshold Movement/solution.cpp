#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
 
    if (n % 2 != 0) {
        cout << "NO
";
        return;
    }
 
    int mn = 2e9; // infinity placeholder for min
    int mx = -2e9; // infinity placeholder for max
 
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            mn = min(mn, w[i]);
        } else {
            mx = max(mx, w[i]);
        }
    }
 
    if (mn - mx >= 2) {
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