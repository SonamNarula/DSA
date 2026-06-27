#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1e15;

struct SegNode {
    vector<long long> dp[2][2];
};

vector<long long> inf_conv(const vector<long long>& A, const vector<long long>& B, int shift) {
    int la = -1, ra = -1;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < INF) {
            if (la == -1) la = i;
            ra = i;
        }
    }
    int lb = -1, rb = -1;
    for (int i = 0; i < B.size(); i++) {
        if (B[i] < INF) {
            if (lb == -1) lb = i;
            rb = i;
        }
    }
    if (la == -1 || lb == -1) {
        return vector<long long>(A.size() + B.size() + shift, INF);
    }

    vector<long long> slopes_a, slopes_b;
    for (int i = la; i < ra; i++) {
        slopes_a.push_back(A[i + 1] - A[i]);
    }
    for (int i = lb; i < rb; i++) {
        slopes_b.push_back(B[i + 1] - B[i]);
    }

    vector<long long> slopes_c(slopes_a.size() + slopes_b.size());
    merge(slopes_a.begin(), slopes_a.end(), slopes_b.begin(), slopes_b.end(), slopes_c.begin());

    int lc = la + lb + shift;
    int c_sz = lc + slopes_c.size() + 1;
    vector<long long> C(c_sz, INF);
    C[lc] = A[la] + B[lb];
    for (int i = 0; i < slopes_c.size(); i++) {
        C[lc + i + 1] = C[lc + i] + slopes_c[i];
    }
    return C;
}

vector<long long> min_vals(const vector<long long>& A, const vector<long long>& B) {
    int sz = max(A.size(), B.size());
    vector<long long> C(sz);
    for (int i = 0; i < sz; i++) {
        long long va = (i < A.size()) ? A[i] : INF;
        long long vb = (i < B.size()) ? B[i] : INF;
        C[i] = min(va, vb);
    }
    return C;
}

SegNode build(int l, int r, const string& s) {
    SegNode res;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            res.dp[a][b] = {INF};
        }
    }
    if (l == r) {
        int cost_s = (s[l] == 'S') ? 0 : 1;
        int cost_r = (s[l] == 'R') ? 0 : 1;
        res.dp[0][0] = {cost_s};
        res.dp[1][1] = {cost_r};
        return res;
    }
    int mid = l + (r - l) / 2;
    SegNode left_node = build(l, mid, s);
    SegNode right_node = build(mid + 1, r, s);

    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                for (int d = 0; d < 2; d++) {
                    int shift = (c == 1 && d == 0) ? 1 : 0;
                    vector<long long> conv = inf_conv(left_node.dp[a][c], right_node.dp[d][b], shift);
                    res.dp[a][b] = min_vals(res.dp[a][b], conv);
                }
            }
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    SegNode root = build(0, n - 1, s);

    vector<long long> ans_vals = {INF};
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            ans_vals = min_vals(ans_vals, root.dp[a][b]);
        }
    }

    vector<int> ans(n + 1, 0);
    for (int t = 0; t < ans_vals.size(); t++) {
        long long cost = ans_vals[t];
        if (cost <= n) {
            ans[cost] = max(ans[cost], t);
        }
    }

    for (int k = 1; k <= n; k++) {
        ans[k] = max(ans[k], ans[k - 1]);
    }

    for (int k = 0; k <= n; k++) {
        cout << ans[k] << (k == n ? "" : " ");
    }
    cout << "\n";
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
