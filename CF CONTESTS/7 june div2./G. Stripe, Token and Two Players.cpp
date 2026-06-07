#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegTree {
    int n;
    vector<int> tree_min;
    vector<int> tree_max;

    SegTree(int n, const vector<int>& V) : n(n) {
        tree_min.resize(4 * n + 5);
        tree_max.resize(4 * n + 5);
        build(1, 1, n, V);
    }

    void build(int node, int l, int r, const vector<int>& V) {
        if (l == r) {
            tree_min[node] = V[l];
            tree_max[node] = V[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, V);
        build(2 * node + 1, mid + 1, r, V);
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree_min[node] = val;
            tree_max[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * node, l, mid, pos, val);
        else update(2 * node + 1, mid + 1, r, pos, val);
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }

    void get_active(int node, int l, int r, int i, vector<pair<int, int>>& active_intervals) {
        if (tree_min[node] > i) {
            active_intervals.push_back({l, r});
            return;
        }
        if (tree_max[node] <= i) {
            return;
        }
        if (l == r) return;
        int mid = (l + r) / 2;
        get_active(2 * node, l, mid, i, active_intervals);
        get_active(2 * node + 1, mid + 1, r, i, active_intervals);
    }

    int query_min(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree_min[node];
        }
        int mid = (l + r) / 2;
        int ans = 1e9;
        if (ql <= mid) ans = min(ans, query_min(2 * node, l, mid, ql, qr));
        if (qr > mid) ans = min(ans, query_min(2 * node + 1, mid + 1, r, ql, qr));
        return ans;
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> V(n + 2);
    for (int P = 1; P <= n + 1; P++) {
        V[P] = n + 1 - P;
    }

    SegTree st(n + 1, V);

    for (int i = n; i >= 2; i--) {
        vector<pair<int, int>> active_intervals;
        st.get_active(1, 1, n + 1, i, active_intervals);

        vector<pair<int, int>> updates;
        for (auto& interval : active_intervals) {
            int L = interval.first;
            int R = interval.second;
            long long max_P = (R == n + 1) ? n : min((long long)n, (long long)R - a[i]);
            if (L <= max_P) {
                for (int P = L; P <= max_P; P++) {
                    updates.push_back({P, i - P});
                }
            }
        }
        for (auto& p : updates) {
            st.update(1, 1, n + 1, p.first, p.second);
        }
    }

    long long max_P_start = min((long long)n, 1LL + a[1]);
    int min_V = st.query_min(1, 1, n + 1, 1, max_P_start);

    if (min_V <= 1) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
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
