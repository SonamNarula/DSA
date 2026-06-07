#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string n;
    cin >> n;
    if (n.size() > 1 && n[0] == '6' && all_of(n.begin() + 1, n.end(), [](char c) { return c == '1'; })) {
        cout << string(n.size() - 1, '1') << " " << "6" << string(n.size() - 1, '0') << "\n";
        return;
    }

    int target = 0;
    for (char c : n) target = (target * 10 + (c - '0')) % 12;

    auto cmp = [](const string &a, const string &b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    };

    auto sub_big = [&](const string &A, const string &B) {
        // return A-B, assume A>=B, both non-negative decimal strings
        string a = A;
        string b = B;
        int i = (int)a.size()-1, j = (int)b.size()-1;
        string res;
        int carry = 0;
        while (i>=0 || j>=0) {
            int da = i>=0 ? a[i]-'0' : 0;
            int db = j>=0 ? b[j]-'0' : 0;
            int cur = da - db - carry;
            if (cur<0) { cur+=10; carry=1; } else carry=0;
            res.push_back('0'+cur);
            i--; j--;
        }
        while (res.size()>1 && res.back()=='0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    };

    auto find_pal = [&](int L, const string &limit, bool bounded) {
        int half = (L + 1) / 2;
        vector<int> pow10(L);
        pow10[0] = 1;
        for (int i = 1; i < L; ++i) pow10[i] = (pow10[i - 1] * 10) % 12;

        vector<vector<vector<int>>> seen(half + 1, vector<vector<int>>(12, vector<int>(2, -1)));
        function<bool(int, int, bool)> can = [&](int pos, int rem, bool tight) {
            if (pos == half) return rem == target;
            int &memo = seen[pos][rem][tight];
            if (memo != -1) return memo == 1;

            int high = tight ? limit[pos] - '0' : 9;
            int low = (pos == 0 && L > 1) ? 1 : 0;
            int mirror = L - 1 - pos;
            int weight = pow10[L - 1 - pos];
            if (mirror != pos) weight = (weight + pow10[L - 1 - mirror]) % 12;

            for (int d = high; d >= low; --d) {
                bool ntight = tight && (d == high);
                if (can(pos + 1, (rem + d * weight) % 12, ntight)) {
                    memo = 1;
                    return true;
                }
            }
            memo = 0;
            return false;
        };

        if (!can(0, 0, bounded)) return string();

        string pal(L, '0');
        int rem = 0;
        bool tight = bounded;
        for (int pos = 0; pos < half; ++pos) {
            int high = tight ? limit[pos] - '0' : 9;
            int low = (pos == 0 && L > 1) ? 1 : 0;
            int mirror = L - 1 - pos;
            int weight = pow10[L - 1 - pos];
            if (mirror != pos) weight = (weight + pow10[L - 1 - mirror]) % 12;

            for (int d = high; d >= low; --d) {
                bool ntight = tight && (d == high);
                int nrem = (rem + d * weight) % 12;
                if (can(pos + 1, nrem, ntight)) {
                    pal[pos] = pal[mirror] = char('0' + d);
                    rem = nrem;
                    tight = ntight;
                    break;
                }
            }
        }

        return pal;
    };

    int L0 = n.size();
    for (int L = L0; L>=1; --L) {
        string limit = (L == L0 ? n : string(L, '9'));
        string pal = find_pal(L, limit, L == L0);
        if (!pal.empty() && (L < L0 || !cmp(n, pal))) {
            string b = sub_big(n, pal);
            cout << pal << " " << b << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
