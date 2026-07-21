#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> adj[200005];
int a[200005];
int L[200005];
int R[200005];
bool ok = true;
 
void dfs(int u) {
    if (adj[u].empty()) {
        L[u] = a[u];
        R[u] = a[u];
        return;
    }
    
    int min_val = 2e9, max_val = -2e9;
    long long sum_len = 0;
    
    for (int v : adj[u]) {
        dfs(v);
        min_val = min(min_val, L[v]);
        max_val = max(max_val, R[v]);
        sum_len += (R[v] - L[v] + 1);
    }
    
    if (sum_len != (max_val - min_val + 1)) {
        ok = false;
    }
    
    int c = adj[u].size();
    vector<pair<int, int>> temp;
    for (int v : adj[u]) {
        temp.push_back({L[v], v});
    }
    sort(temp.begin(), temp.end());
    
    int start = -1;
    int target = adj[u][0];
    for (int i = 0; i < c; i++) {
        if (temp[i].second == target) {
            start = i;
            break;
        }
    }
    
    if (start == -1) {
        ok = false;
    } else {
        for (int i = 0; i < c; i++) {
            if (temp[(start + i) % c].second != adj[u][i]) {
                ok = false;
                break;
            }
        }
    }
    
    L[u] = min_val;
    R[u] = max_val;
}
 
void solve() {
    int n;
    if (!(cin >> n)) return;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    ok = true;
    dfs(1);
    
    if (ok) {
        cout << "YES
";
    } else {
        cout << "NO
";
    }
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