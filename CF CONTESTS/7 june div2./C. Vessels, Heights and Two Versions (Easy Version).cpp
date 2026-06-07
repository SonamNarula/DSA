
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int size(int x) {
        return sz[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;

    vector<long long> h(n);
    for (long long &x : h) cin >> x;

    vector<pair<long long, int>> edges;
    for (int i = 0; i < n; ++i) {
        edges.push_back({h[i], i});
    }
    sort(edges.begin(), edges.end());

    for (int empty = 0; empty < n; ++empty) {
        DSU dsu(n);
        long long ans = 0;
        long long level = 1;
        int ptr = 0;

        while (ptr < n) {
            long long next_height = edges[ptr].first;
            ans += (next_height - level + 1) * (n - dsu.size(empty));

            while (ptr < n && edges[ptr].first == next_height) {
                int edge = edges[ptr].second;
                dsu.unite(edge, (edge + 1) % n);
                ++ptr;
            }

            level = next_height + 1;
        }

        cout << ans << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
