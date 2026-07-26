#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 200005;
const int INF = 1e9;
 
// Segment Tree and data arrays declared globally for speed
int tree_val[800005];
int lazy_val[800005];
int p[MAXN];
int pos[MAXN];
vector<int> enters[MAXN];
vector<int> leaves[MAXN];
int n;
 
void push(int node) {
    if (lazy_val[node] != 0) {
        int val = lazy_val[node];
        tree_val[2 * node] += val;
        lazy_val[2 * node] += val;
        tree_val[2 * node + 1] += val;
        lazy_val[2 * node + 1] += val;
        lazy_val[node] = 0;
    }
}
 
void update(int node, int start, int end, int l, int r, int val) {
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        tree_val[node] += val;
        lazy_val[node] += val;
        return;
    }
    push(node);
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
    tree_val[node] = max(tree_val[2 * node], tree_val[2 * node + 1]);
}
 
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return -INF;
    if (l <= start && end <= r) return tree_val[node];
    push(node);
    int mid = (start + end) / 2;
    return max(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}
 
void circular_update(int L, int R, int val) {
    if (L == R) return;
    if (L < R) {
        update(1, 0, n - 1, L, R - 1, val);
    } else {
        update(1, 0, n - 1, L, n - 1, val);
        update(1, 0, n - 1, 0, R - 1, val);
    }
}
 
int circular_query(int L, int R) {
    if (L == R) {
        return query(1, 0, n - 1, 0, n - 1);
    }
    if (L < R) {
        return query(1, 0, n - 1, L, R - 1);
    } else {
        return max(query(1, 0, n - 1, L, n - 1), query(1, 0, n - 1, 0, R - 1));
    }
}
 
bool in_I(int pt, int A, int B) {
    if (A == B) return false;
    int d_pt = (pt - A + n) % n;
    int d_B = (B - A + n) % n;
    return d_pt > 0 && d_pt <= d_B;
}
 
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }
 
    if (n == 1) {
        cout << "1
";
        return;
    }
 
    // Reset segment tree and event vectors
    for (int i = 0; i < 4 * n + 5; ++i) {
        tree_val[i] = 0;
        lazy_val[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        enters[i].clear();
        leaves[i].clear();
    }
 
    for (int x = 2; x <= n; ++x) {
        if (in_I(0, pos[x - 1], pos[x])) {
            circular_update(pos[x], pos[x - 1], 1);
        }
    }
 
    for (int x = 2; x <= n; ++x) {
        int ent = (pos[x - 1] + 1) % n;
        enters[ent].push_back(x);
        int lv = (pos[x] + 1) % n;
        leaves[lv].push_back(x);
    }
 
    int pos1 = pos[1];
    int ans = 0;
 
    for (int s = 0; s < n; ++s) {
        if (s == pos1) {
            int max1 = circular_query(pos1, pos1);
            if (max1 <= 1) {
                ans++;
            }
        } else {
            int max1 = circular_query(pos1, s);
            int max2 = circular_query(s, pos1);
            if (max1 <= 1 && max2 <= 2) {
                ans++;
            }
        }
 
        int next_s = (s + 1) % n;
        for (int x : leaves[next_s]) {
            circular_update(pos[x], pos[x - 1], -1);
        }
        for (int x : enters[next_s]) {
            circular_update(pos[x], pos[x - 1], 1);
        }
    }
 
    cout << ans << "
";
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