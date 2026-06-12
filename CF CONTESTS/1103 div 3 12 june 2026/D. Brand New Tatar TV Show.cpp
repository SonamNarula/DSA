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
    
    // Sort the array to group identical elements
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
    int num_L = 0; // Tracks the number of losing states (0) in the active window
    
    for (int i = m - 1; i >= 0; i--) {
        // Step 1: Add the adjacent state (i + 1) to the active range
        if (i + 1 < m && i + 1 <= R) {
            if (dp[i + 1] == 0) {
                num_L++;
            }
        }
        
        // Step 2: Shrink R from the right if the element value exceeds v[i] + k
        while (R > i && v[R] > v[i] + k) {
            if (dp[R] == 0) {
                num_L--;
            }
            R--;
        }
        
        // Step 3: Check if there's any L state in the jump range [i + 1, R]
        if (i + 1 <= R && num_L > 0) {
            dp[i] = 1; // Win
        } else {
            // If no larger transitions lead to L, we play parity on identical elements
            dp[i] = (cnt[i] % 2 == 0) ? 1 : 0; 
        }
    }
    
    // Egor wins if Arseniy can choose any v[i] that leaves Egor in a winning state (dp[i] == 1)
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
    // Fast I/O for competitive programming constraints
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
