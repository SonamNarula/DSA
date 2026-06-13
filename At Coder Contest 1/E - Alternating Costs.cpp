#include <iostream>
#include <vector>

using namespace std;

long long abs_val(long long val) {
    return val < 0 ? -val : val;
}

long long get_cost(long long h, long long v, long long A, long long B) {
    long long n = h + v;
    long long cb = 0;
    if ((h - v) % 2 == 0) {
        cb = abs_val(h - v) / 2;
    } else {
        if (h > v) {
            cb = (h - v - 1) / 2;
        } else {
            cb = (v - h + 1) / 2;
        }
    }
    long long ca = n - cb;
    return ca * A + cb * B;
}

void solve() {
    long long A, B, X, Y;
    if (!(cin >> A >> B >> X >> Y)) return;
    
    X = abs_val(X);
    Y = abs_val(Y);
    
    if (A > B) {
        swap(A, B);
        swap(X, Y);
    }
    
    long long h0 = X;
    long long v0 = Y;
    
    vector<long long> cand_h;
    vector<long long> cand_v;
    
    for (long long val : {h0, v0, v0 - 1, v0 + 1}) {
        if (val >= h0 && (val - h0) % 2 == 0) {
            cand_h.push_back(val);
        }
    }
    
    for (long long val : {v0, h0, h0 - 1, h0 + 1}) {
        if (val >= v0 && (val - v0) % 2 == 0) {
            cand_v.push_back(val);
        }
    }
    
    long long ans = -1;
    
    for (long long v : cand_v) {
        long long cost = get_cost(h0, v, A, B);
        if (ans == -1 || cost < ans) {
            ans = cost;
        }
    }
    
    for (long long h : cand_h) {
        long long cost = get_cost(h, v0, A, B);
        if (ans == -1 || cost < ans) {
            ans = cost;
        }
    }
    
    cout << ans << "\n";
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
