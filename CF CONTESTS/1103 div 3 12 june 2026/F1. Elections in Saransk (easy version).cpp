#include <iostream>
#include <vector>

using namespace std;

const int MAX_A = 500000;
int spf[MAX_A + 1];


void sieve() {
    for (int i = 1; i <= MAX_A; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAX_A; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAX_A; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}


int sum_exp[MAX_A + 1];
vector<int> modified;

void solve() {
    int n, x;
    cin >> n >> x; 
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        while (val > 1) {
            int p = spf[val];
            int cnt = 0;
            while (val % p == 0) {
                cnt++;
                val /= p;
            }
            if (sum_exp[p] == 0) {
                modified.push_back(p);
            }
            sum_exp[p] += cnt;
        }
    }
    
    long long ans = 1;
    long long MOD = 1000000007;
    
    for (int p : modified) {
        long long choices = (1 + sum_exp[p]) % MOD;
        ans = (ans * choices) % MOD;
        sum_exp[p] = 0; 
    }
    modified.clear();
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
