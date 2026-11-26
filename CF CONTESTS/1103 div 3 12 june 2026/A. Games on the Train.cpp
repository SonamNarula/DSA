#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        
        // Start min and max with the first element of the array
        int mn = h[0];
        int mx = h[0];
        
        // Find actual min and max by comparing elements
        for (int i = 1; i < n; i++) {
            if (h[i] < mn) {
                mn = h[i];
            }
            if (h[i] > mx) {
                mx = h[i];
            }
        }
        
        // Calculate the result
        int ans = mx - mn + 1;
        cout << ans << "\n";
    }
    
    return 0;
}
