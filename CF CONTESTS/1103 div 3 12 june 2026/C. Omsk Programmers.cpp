#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long get_prod(long long v, long long x, int p, long long limit) {
    long long prod = v;
    for (int i = 0; i < p; i++) {
        if (prod > limit / x) {
            return limit + 1; 
        }
        prod *= x;
    }
    return prod;
}

void solve() {
    long long a, b, x;
    cin >> a >> b >> x;
    

    vector<long long> candidates;
    
    long long cur_a = a;
    candidates.push_back(cur_a);
    while (cur_a > 0) {
        cur_a /= x;
        candidates.push_back(cur_a);
    }
    
    long long cur_b = b;
    candidates.push_back(cur_b);
    while (cur_b > 0) {
        cur_b /= x;
        candidates.push_back(cur_b);
    }
    

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    
    long long ans = 1e18; 
    for (long long v : candidates) {
        

        long long cost_a = 1e18;
        for (int p = 0; p <= 32; p++) {
            long long div_val = a;
            for (int i = 0; i < p; i++) {
                div_val /= x;
            }

            if (v >= div_val) {
                long long prod = get_prod(v, x, p, 2e9);
                long long additions = max(0LL, prod - a);
                cost_a = min(cost_a, p + additions);
            }
        }
        

        long long cost_b = 1e18;
        for (int q = 0; q <= 32; q++) {
            long long div_val = b;
            for (int i = 0; i < q; i++) {
                div_val /= x;
            }
            if (v >= div_val) {
                long long prod = get_prod(v, x, q, 2e9);
                long long additions = max(0LL, prod - b);
                cost_b = min(cost_b, q + additions);
            }
        }
        
        ans = min(ans, cost_a + cost_b);
    }
    
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
