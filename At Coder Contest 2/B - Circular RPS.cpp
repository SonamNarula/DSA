#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Case 1: Only one type of winner is active
long long solve_1(long long a, long long b, long long c) {
    if (a <= 0) return 0;
    // If no elements of type C exist, and we have enough neighbors of B, we can alternate
    if (c == 0 && a <= b) return a;
    return max(0LL, min(a, b - 1));
}

// Case 2: Exactly two types of winners are active
long long solve_2(long long a, long long b, long long c) {
    if (a < 3 || b < 2 || c < 1) return 0;
    return min(a - 1, b - 1 + c);
}

// Case 3: All three types of winners are active
long long solve_3(long long a, long long b, long long c) {
    long long A_prime = a - 3;
    long long B_prime = b - 3;
    long long C_prime = c - 3;
    if (A_prime < 0 || B_prime < 0 || C_prime < 0) return 0;
    
    long long sum_all = (A_prime + B_prime + C_prime) / 2;
    long long ab = A_prime + B_prime;
    long long bc = B_prime + C_prime;
    long long ca = C_prime + A_prime;
    
    return min({sum_all, ab, bc, ca}) + 3;
}

void solve() {
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return;
    
    long long ans = 0;
    
    // Check Case 1: only one active winner type
    ans = max(ans, solve_1(a, b, c)); // type 0 winners
    ans = max(ans, solve_1(b, c, a)); // type 1 winners
    ans = max(ans, solve_1(c, a, b)); // type 2 winners
    
    // Check Case 2: exactly two active winner types
    ans = max(ans, solve_2(a, b, c)); // type 0 and 2 winners
    ans = max(ans, solve_2(b, c, a)); // type 1 and 0 winners
    ans = max(ans, solve_2(c, a, b)); // type 2 and 1 winners
    
    // Check Case 3: all three active winner types
    ans = max(ans, solve_3(a, b, c));
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
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
