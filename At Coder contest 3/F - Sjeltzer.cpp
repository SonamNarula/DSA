#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Flat 1D array to represent the 6D grid of size 10^6
long long P[1000000];

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; ++i) {
            string s;
            long long v;
            cin >> s >> v;
            int idx = stoi(s);
            P[idx] += v;
        }

        // Multi-dimensional prefix sum (SOS DP style)
        int p = 1;
        for (int d = 0; d < 6; ++d) {
            for (int i = 0; i < 1000000; ++i) {
                int digit = (i / p) % 10;
                if (digit > 0) {
                    P[i] += P[i - p];
                }
            }
            p *= 10;
        }

        int q;
        if (cin >> q) {
            while (q--) {
                string x, y;
                cin >> x >> y;

                // Decode digits
                int X[6], Y[6];
                bool possible = true;
                for (int i = 0; i < 6; ++i) {
                    X[i] = x[5 - i] - '0';
                    Y[i] = y[5 - i] - '0';
                    if (X[i] > Y[i]) {
                        possible = false;
                    }
                }

                if (!possible) {
                    cout << 0 << "\n";
                    continue;
                }

                // Precompute values for coordinates to avoid operations inside the hot mask loop
                int val[6][2];
                int neg_mask = 0;
                int p_val = 1;
                for (int d = 0; d < 6; ++d) {
                    val[d][0] = Y[d] * p_val;
                    if (X[d] - 1 < 0) {
                        neg_mask |= (1 << d);
                        val[d][1] = 0;
                    } else {
                        val[d][1] = (X[d] - 1) * p_val;
                    }
                    p_val *= 10;
                }

                long long ans = 0;
                // Inclusion-exclusion over 2^6 = 64 subsets
                for (int mask = 0; mask < 64; ++mask) {
                    // Skip invalid masks where one of the coordinates is negative
                    if (mask & neg_mask) continue;

                    int idx = val[0][(mask >> 0) & 1] +
                              val[1][(mask >> 1) & 1] +
                              val[2][(mask >> 2) & 1] +
                              val[3][(mask >> 3) & 1] +
                              val[4][(mask >> 4) & 1] +
                              val[5][(mask >> 5) & 1];

                    // Use fast hardware-accelerated popcount
                    int bits = __builtin_popcount(mask);
                    if (bits & 1) {
                        ans -= P[idx];
                    } else {
                        ans += P[idx];
                    }
                }

                cout << ans << "\n";
            }
        }
    }

    return 0;
}
