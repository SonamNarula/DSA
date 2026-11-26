#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MOD = 1e9 + 7;

vector<long long> fact;
vector<long long> inv;

void precompute(int n) {
    fact.resize(n + 1);
    inv.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<int> L_bound(n + 2);
    vector<int> R_bound(n + 2);
    vector<int> root(n + 2, 0);
    vector<bool> reconstructed(n + 2, false);
    vector<bool> in_queue(n + 2, false);
    vector<int> subtree_size(n + 2, 0);
    
    // Initialize bounds for unassigned elements
    for (int i = 1; i <= n; i++) {
        L_bound[i] = i;
        R_bound[i] = i - 1;
    }
    
    auto get_L = [&](int i) {
        if (i - 1 >= 1 && reconstructed[i - 1]) {
            return L_bound[i - 1];
        }
        return i;
    };
    
    auto get_R = [&](int i) {
        if (i + 1 <= n && reconstructed[i + 1]) {
            return R_bound[i + 1];
        }
        return i;
    };
    
    auto is_ready = [&](int i) {
        if (reconstructed[i] || in_queue[i]) return false;
        int L = get_L(i);
        int R = get_R(i);
        long long req = (long long)(i - L + 1) * (R - i + 1);
        return a[i] == req;
    };
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (is_ready(i)) {
            q.push(i);
            in_queue[i] = true;
        }
    }
    
    int merges = 0;
    int root_node = 0;
    
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        
        int L = get_L(i);
        int R = get_R(i);
        long long req = (long long)(i - L + 1) * (R - i + 1);
        if (a[i] != req) {
            in_queue[i] = false;
            continue;
        }
        
        reconstructed[i] = true;
        merges++;
        root_node = i;
        
        L_bound[R] = L;
        R_bound[L] = R;
        root[L] = i;
        root[R] = i;
        subtree_size[i] = R - L + 1;
        
        if (L - 1 >= 1 && is_ready(L - 1)) {
            q.push(L - 1);
            in_queue[L - 1] = true;
        }
        if (R + 1 <= n && is_ready(R + 1)) {
            q.push(R + 1);
            in_queue[R + 1] = true;
        }
    }
    
    if (merges != n || subtree_size[root_node] != n) {
        cout << 0 << "\n";
        return;
    }
    
    long long ans = fact[n];
    for (int i = 1; i <= n; i++) {
        ans = (ans * inv[subtree_size[i]]) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute(500005);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
