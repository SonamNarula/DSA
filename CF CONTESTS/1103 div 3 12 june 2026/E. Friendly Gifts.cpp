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
    
    vector<vector<pair<int, int>>> good_segs(n / 2 + 1);
    
   
    vector<int> last_seen(n + 1, -1);
    
    for (int l = 0; l < n; l++) {
        int mn = a[l];
        int mx = a[l];
        last_seen[a[l]] = l;
        
        for (int r = l; r < n; r++) {
            if (r > l) {
                if (last_seen[a[r]] == l) {

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
            

            while (L_ptr < S.size() && S[L_ptr].first + len <= r_l) {
                int l_v = S[L_ptr].second;
                if (min_start[l_v] == 1e9) {
                    modified.push_back(l_v);
                }
                min_start[l_v] = min(min_start[l_v], S[L_ptr].first);
                L_ptr++;
            }
            

            if (r_v - len >= 1 && min_start[r_v - len] != 1e9) {
                found = true;
                break;
            }
            if (r_v + len <= n && min_start[r_v + len] != 1e9) {
                found = true;
                break;
            }
        }
        

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
