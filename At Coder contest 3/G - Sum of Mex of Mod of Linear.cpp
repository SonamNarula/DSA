#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <chrono>

using namespace std;

// 128-bit integer struct for intermediate calculations to avoid overflow
struct Result {
    __int128 f, g, h;
};

// Euclidean-like floor sum algorithm
// All parameters and divisions are 64-bit to use CPU hardware division (extremely fast).
// 128-bit is used only for addition/multiplication results that can overflow.
Result solve(long long n, long long a, long long b, long long c) {
    if (a == 0) {
        long long q = b / c;
        __int128 f = (__int128)n * q;
        __int128 g = (__int128)n * q * q;
        __int128 h = ((__int128)n * (n - 1) / 2) * q;
        return {f, g, h};
    }
    
    if (a >= c || b >= c) {
        long long qa = a / c;
        long long qb = b / c;
        long long a0 = a % c;
        long long b0 = b % c;
        Result r = solve(n, a0, b0, c);
        
        __int128 sum_x2 = (__int128)(n - 1) * n * (2 * n - 1) / 6;
        __int128 sum_x = (__int128)n * (n - 1) / 2;
        
        __int128 f = (__int128)qa * sum_x + (__int128)qb * n + r.f;
        __int128 g = (__int128)qa * qa * sum_x2 + 2 * (__int128)qa * qb * sum_x + (__int128)qb * qb * n + r.g + 2 * (__int128)qa * r.h + 2 * (__int128)qb * r.f;
        __int128 h = (__int128)qa * sum_x2 + (__int128)qb * sum_x + r.h;
        return {f, g, h};
    }

    long long y_max = (a * n + b) / c;
    if (y_max == 0) {
        return {0, 0, 0};
    }
    
    Result r = solve(y_max, c, c - b - 1, a);
    
    __int128 f = (__int128)(n - 1) * y_max - r.f;
    __int128 g = (__int128)(n - 1) * y_max * y_max - 2 * r.h - r.f;
    __int128 h = (__int128)n * (n - 1) / 2 * y_max - (r.g + r.f) / 2;
    return {f, g, h};
}

long long K_global, C_global, M_global;
Result R_global_0;
Result R_global_q;
__int128 R_sum_q;

// Custom hash for unordered_map to prevent anti-hash tests
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Memoization tables for the two different solve() queries
unordered_map<long long, Result, custom_hash> memo1;
unordered_map<long long, Result, custom_hash> memo2;

// Computes both F0(R) and F1(R) simultaneously and uses memoization to avoid redundant solves
void get_prefix_sums(long long R, long long &s0, long long &s1) {
    if (R < 0) {
        s0 = 0;
        s1 = 0;
        return;
    }
    if (C_global == 0) {
        s0 = K_global;
        s1 = 0;
        return;
    }
    
    Result r2;
    auto it1 = memo1.find(R);
    if (it1 != memo1.end()) {
        r2 = it1->second;
    } else {
        r2 = solve(K_global, C_global, M_global - R - 1, M_global);
        memo1[R] = r2;
    }
    
    __int128 ans0 = K_global + R_global_0.f - r2.f;
    s0 = (long long)ans0;
    
    __int128 sum_k = (__int128)K_global * (K_global - 1) / 2 + R_global_0.h - r2.h;
    
    __int128 num = (__int128)C_global * K_global - 1 - R;
    __int128 Q1 = num / M_global;
    __int128 rem = num % M_global;
    if (rem < 0) {
        Q1--;
    }
    
    __int128 h_q1 = 0;
    __int128 sum_q1 = 0;
    if (Q1 >= 0) {
        Result r_q1;
        auto it2 = memo2.find(R);
        if (it2 != memo2.end()) {
            r_q1 = it2->second;
        } else {
            r_q1 = solve(Q1 + 1, M_global, R, C_global);
            memo2[R] = r_q1;
        }
        h_q1 = r_q1.h;
        sum_q1 = Q1 * (Q1 + 1) / 2;
    }
    
    __int128 S2 = h_q1 - R_global_q.h + R_sum_q + (__int128)(K_global - 1) * (R_sum_q - sum_q1);
    
    __int128 ans1 = (__int128)C_global * sum_k - (__int128)M_global * S2;
    s1 = (long long)ans1;
}

set<pair<int, int>> intervals;
map<int, int> val_freq;
long long TotalSum = 0;

long long get_contrib(int l, int r) {
    int start = l;
    if (l == 0) {
        auto it = intervals.end();
        if (it != intervals.begin()) {
            it--;
            if (it->second == M_global - 1) {
                start = it->first;
            }
        }
    }
    
    long long s0_r, s1_r;
    get_prefix_sums(r, s0_r, s1_r);
    
    long long s0_l, s1_l;
    get_prefix_sums(l - 1, s0_l, s1_l);
    
    long long s0 = s0_r - s0_l;
    long long s1 = s1_r - s1_l;
    
    if (start <= l) {
        return s1 - (start - 1) * s0;
    } else {
        return s1 + (M_global - start + 1) * s0;
    }
}

void update_ends(int sign) {
    if (intervals.empty()) return;
    auto first = *intervals.begin();
    auto last = *intervals.rbegin();
    
    TotalSum += sign * get_contrib(first.first, first.second);
    if (first != last) {
        TotalSum += sign * get_contrib(last.first, last.second);
    }
}

void insert_val(int x) {
    if (val_freq[x]++ > 0) return;
    
    update_ends(-1);
    
    auto it = intervals.upper_bound({x, M_global});
    bool has_right = (it != intervals.end() && it->first == x + 1);
    bool has_left = false;
    auto lit = it;
    if (it != intervals.begin()) {
        lit = prev(it);
        if (lit->second == x - 1) {
            has_left = true;
        }
    }
    
    int new_l = x, new_r = x;
    if (has_left && has_right) {
        auto first = *intervals.begin();
        auto last = *intervals.rbegin();
        if (*lit != first && *lit != last) {
            TotalSum -= get_contrib(lit->first, lit->second);
        }
        if (*it != first && *it != last) {
            TotalSum -= get_contrib(it->first, it->second);
        }
        new_l = lit->first;
        new_r = it->second;
        intervals.erase(lit);
        intervals.erase(it);
    } else if (has_left) {
        auto first = *intervals.begin();
        auto last = *intervals.rbegin();
        if (*lit != first && *lit != last) {
            TotalSum -= get_contrib(lit->first, lit->second);
        }
        new_l = lit->first;
        intervals.erase(lit);
    } else if (has_right) {
        auto first = *intervals.begin();
        auto last = *intervals.rbegin();
        if (*it != first && *it != last) {
            TotalSum -= get_contrib(it->first, it->second);
        }
        new_r = it->second;
        intervals.erase(it);
    }
    
    intervals.insert({new_l, new_r});
    
    auto new_first = *intervals.begin();
    auto new_last = *intervals.rbegin();
    if (pair<int, int>{new_l, new_r} != new_first && pair<int, int>{new_l, new_r} != new_last) {
        TotalSum += get_contrib(new_l, new_r);
    }
    
    update_ends(1);
}

void erase_val(int x) {
    if (--val_freq[x] > 0) return;
    
    update_ends(-1);
    
    auto it = intervals.upper_bound({x, M_global});
    auto lit = prev(it);
    int l = lit->first;
    int r = lit->second;
    
    auto first = *intervals.begin();
    auto last = *intervals.rbegin();
    if (*lit != first && *lit != last) {
        TotalSum -= get_contrib(l, r);
    }
    
    intervals.erase(lit);
    
    if (l <= x - 1) {
        intervals.insert({l, x - 1});
    }
    if (x + 1 <= r) {
        intervals.insert({x + 1, r});
    }
    
    if (!intervals.empty()) {
        auto new_first = *intervals.begin();
        auto new_last = *intervals.rbegin();
        
        if (l <= x - 1) {
            pair<int, int> left_int{l, x - 1};
            if (left_int != new_first && left_int != new_last) {
                TotalSum += get_contrib(l, x - 1);
            }
        }
        if (x + 1 <= r) {
            pair<int, int> right_int{x + 1, r};
            if (right_int != new_first && right_int != new_last) {
                TotalSum += get_contrib(x + 1, r);
            }
        }
    }
    
    update_ends(1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long m, c, k;
    if (cin >> n >> m >> c >> k) {
        K_global = k;
        C_global = c;
        M_global = m;
        
        if (c > 0) {
            R_global_0 = solve(k, c, 0, m);
            long long Q = (c * k - 1) / m;
            R_global_q = solve(Q + 1, m, c - 1, c);
            R_sum_q = (__int128)Q * (Q + 1) / 2;
        }
        
        // Reserve memory for the hash maps to minimize rehashing time
        memo1.reserve(400000);
        memo2.reserve(400000);
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int d0_val = (m - a[i]) % m;
            insert_val(d0_val);
        }
        
        int q;
        if (cin >> q) {
            while (q--) {
                int idx, x;
                cin >> idx >> x;
                idx--;
                
                int old_d0 = (m - a[idx]) % m;
                erase_val(old_d0);
                
                a[idx] = x;
                int new_d0 = (m - x) % m;
                insert_val(new_d0);
                
                cout << TotalSum << "\n";
            }
        }
    }
    return 0;
}
