#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    int max_time = 0;
    int cur_len = 0;
 
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            cur_len++;
        } else {
            if (cur_len > 0) {
                max_time = max(max_time, (cur_len + 1) / 2);
                cur_len = 0;
            }
        }
    }
 
    if (cur_len > 0) {
        max_time = max(max_time, (cur_len + 1) / 2);
    }
 
    cout << max_time << "
";
}
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}