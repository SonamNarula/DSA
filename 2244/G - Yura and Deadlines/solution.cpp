#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
long long tree[200005];
vector<int> activate[200005];
long long a[200005];
long long dp[200005];
 
void update(int i, long long val, int n) {
    for (; i <= n; i += i & -i) {
        tree[i] = max(tree[i], val);
    }
}
 
long long query(int i) {
    long long res = 0;
    for (; i > 0; i -= i & -i) {
        res = max(res, tree[i]);
    }
    return res;
}
 
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    for (int i = 0; i <= n + 1; i++) {
        tree[i] = 0;
        activate[i].clear();
        dp[i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        long long act_time = i + a[i] + 1;
        if (act_time <= n) {
            activate[act_time].push_back(i);
        }
    }
    
    long long ans = 0;
    for (int j = 1; j <= n; j++) {
        for (int i : activate[j]) {
            update(i, dp[i], n);
        }
        long long limit = j - a[j] - 1;
        long long best_prev = 0;
        if (limit >= 1) {
            best_prev = query(limit);
        }
        dp[j] = a[j] + best_prev;
        ans = max(ans, dp[j]);
    }
    
    cout << ans << "
";
}
 
int main() {
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