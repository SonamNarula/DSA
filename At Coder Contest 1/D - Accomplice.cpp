#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 1000005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, d;
    if (cin >> n >> d) {
        vector<int> arr(MAX_VAL, 0);
        for (int i = 0; i < n; i++) {
            int s, t;
            cin >> s >> t;
            if (s <= t - d) {
                arr[s]++;
                arr[t - d + 1]--;
            }
        }
        
        long long ans = 0;
        int cur = 0;
        for (int x = 1; x < MAX_VAL; x++) {
            cur += arr[x];
            ans += (long long)cur * (cur - 1) / 2;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
