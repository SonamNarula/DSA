#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    

    vector<int> cnt(k, 0);
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt[i % k]++;
        }
    }
    

    bool ok = true;
    for (int i = 0; i < k; i++) {
        if (cnt[i] % 2 != 0) {
            ok = false;
            break;
        }
    }
    
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
