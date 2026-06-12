#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // good_segs[len] stores pairs of {starting_index, min_value} for valid good subarrays
    vector<vector<pair<int, int>>> good_segs(n / 2 + 1);
    
    // last_seen tracks the last index where a value appeared to check for duplicates
    // Using start index 'l' as the marker avoids clearing it in O(n) every time
    vector<int> last_seen(n + 1, -1);
    
    for (int l = 0; l < n; l++) {
        int mn = a[l];
        int mx = a[l];
        last_seen[a[l]] = l;
        
        for (int r = l; r < n; r++) {
            if (r > l) {
                if (last_seen[a[r]] == l) {
                    // Duplicate found, we cannot expand further
                    break;
                }
                last_seen[a[r]] = l;
                mn = min(mn, a[r]);
                mx = max(mx, a[r]);
            }
            
            int len = r - l + 1;
            if (mx - mn == len - 1) {
                if (len <= n / 2) {
                    good_segs[len].push_back({l, mn});
                }
            }
        }
    }
    
    int ans = 0;
    
    vector<int> min_start(n + 2, 1e9);
    vector<int> modified;
    
    // Check lengths from max possible (n/2) down to 1
    for (int len = n / 2; len >= 1; len--) {
        auto& S = good_segs[len];
        if (S.empty()) {
            continue;
        }
        
        bool found = false;
        int L_ptr = 0;
        
        for (int R_ptr = 0; R_ptr < S.size(); R_ptr++) {
            int r_l = S[R_ptr].first;
            int r_v = S[R_ptr].second;
            
            // Add elements to active set if they satisfy the non-overlapping constraint
            while (L_ptr < S.size() && S[L_ptr].first + len <= r_l) {
                int l_v = S[L_ptr].second;
                if (min_start[l_v] == 1e9) {
                    modified.push_back(l_v);
                }
                min_start[l_v] = min(min_start[l_v], S[L_ptr].first);
                L_ptr++;
            }
            
            // Check if we have a match
            if (r_v - len >= 1 && min_start[r_v - len] != 1e9) {
                found = true;
                break;
            }
            if (r_v + len <= n && min_start[r_v + len] != 1e9) {
                found = true;
                break;
            }
        }
        
        // Reset min_start values for the next iteration
        for (int v : modified) {
            min_start[v] = 1e9;
        }
        modified.clear();
        
        if (found) {
            ans = len;
            break;
        }
    }
    
    cout << ans << "\n";
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
