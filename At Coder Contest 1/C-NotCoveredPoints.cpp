#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        vector<int> y_val(n + 1);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            y_val[x] = y;
        }
        
        int ans = 0;
        int min_y = n + 1;
        for (int x = 1; x <= n; x++) {
            if (y_val[x] < min_y) {
                ans++;
                min_y = y_val[x];
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
