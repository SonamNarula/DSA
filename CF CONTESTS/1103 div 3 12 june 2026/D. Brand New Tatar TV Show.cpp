#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    

    sort(a.begin(), a.end());
    
    vector<int> v;
    vector<int> cnt;
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            v.push_back(a[i]);
            cnt.push_back(1);
        } else {
            cnt.back()++;
        }
    }
    
    int m = v.size();
    vector<int> dp(m, 0); // 1 for Win (W), 0 for Loss (L)
    
    int R = m - 1;
    int num_L = 0; 
    
    for (int i = m - 1; i >= 0; i--) {

        if (i + 1 < m && i + 1 <= R) {
            if (dp[i + 1] == 0) {
                num_L++;
            }
        }
        

        while (R > i && v[R] > v[i] + k) {
            if (dp[R] == 0) {
                num_L--;
            }
            R--;
        }
        

        if (i + 1 <= R && num_L > 0) {
            dp[i] = 1; // Win
        } else {

            dp[i] = (cnt[i] % 2 == 0) ? 1 : 0; 
        }
    }
    

    bool possible = false;
    for (int i = 0; i < m; i++) {
        if (dp[i] == 1) {
            possible = true;
            break;
        }
    }
    
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
