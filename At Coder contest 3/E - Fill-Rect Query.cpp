#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard input/output streams for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    if (cin >> h >> w >> q) {
        // Flatten 2D grid to 1D vector of size (h + 2) * (w + 2)
        int stride = w + 2;
        vector<int> g((h + 2) * stride, 0);
        vector<char> char_map(q + 1, 'A');

        for (int i = 1; i <= q; i++) {
            int r, c;
            char x;
            cin >> r >> c >> x;
            char_map[i] = x;
            int idx = r * stride + c;
            if (i > g[idx]) {
                g[idx] = i;
            }
        }

        // DP table for suffix maximum
        vector<int> v((h + 2) * stride, 0);
        for (int r = h; r >= 1; r--) {
            for (int c = w; c >= 1; c--) {
                int idx = r * stride + c;
                int val = g[idx];

                int val_down = v[(r + 1) * stride + c];
                if (val_down > val) val = val_down;

                int val_right = v[r * stride + (c + 1)];
                if (val_right > val) val = val_right;

                v[idx] = val;
            }
        }

        // Print final cropped image
        for (int r = 1; r <= h; r++) {
            string row_str = "";
            for (int c = 1; c <= w; c++) {
                row_str += char_map[v[r * stride + c]];
            }
            cout << row_str << "\n";
        }
    }

    return 0;
}
