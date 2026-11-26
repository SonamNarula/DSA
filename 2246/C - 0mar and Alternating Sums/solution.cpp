#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll MOD = 1000000007;
 
ll power(ll a, ll b) {
    ll r = 1;
    a %= MOD;
    while(b > 0) {
        if(b & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return r;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int c = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == -1) c++;
    }
    
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) continue;
        if(v.empty() || v.back().first != a[i]) {
            v.push_back({a[i], 1});
        } else {
            v.back().second++;
        }
    }
    
    ll n0 = 1;
    for(int i = 0; i < v.size(); i++) {
        n0 = (n0 * power(2, v[i].second - 1)) % MOD;
    }
    
    int p = 0;
    for(int i = 0; i + 1 < v.size(); i++) {
        if(v[i+1].first == v[i].first + 1) {
            p++;
        }
    }
    
    ll n_minus_1 = (n0 * p) % MOD;
    
    if(c == 0) {
        cout << n0 << "
";
    } else {
        ll ans = (power(2, c - 1) * ((n0 + n_minus_1) % MOD)) % MOD;
        cout << ans << "
";
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}