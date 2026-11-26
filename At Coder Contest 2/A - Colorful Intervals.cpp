#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    // min_l[r] stores the minimum L_j among all intervals ending at r
    vector<int> min_l(n + 2, INF);
    int k = 1;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        min_l[r] = min(min_l[r], l);
        k = max(k, r - l + 1); // K is the size of the largest interval
    }
    
    // limit[i] will store the minimum left endpoint of any interval covering i
    vector<int> limit(n + 2, INF);
    for (int i = n; i >= 1; i--) {
        limit[i] = min(min_l[i], limit[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        limit[i] = min(limit[i], i);
    }
    
    vector<int> ans(n + 1, 0);
    vector<int> freq(k + 1, 0);
    
    int cur_l = 1;
    int min_avail = 1;
    for (int y = 1; y <= n; y++) {
        // Add the previous element's color to the active window
        if (y > 1) {
            int val = ans[y - 1];
            freq[val]++;
        }
        
        // Shrink the window from the left to only include elements >= limit[y]
        int target_l = limit[y];
        while (cur_l < target_l) {
            int val = ans[cur_l];
            freq[val]--;
            if (freq[val] == 0) {
                min_avail = min(min_avail, val);
            }
            cur_l++;
        }
        
        // Find the smallest available color in {1, ..., K}
        while (min_avail <= k && freq[min_avail] > 0) {
            min_avail++;
        }
        
        ans[y] = min_avail;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize input/output operations
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
