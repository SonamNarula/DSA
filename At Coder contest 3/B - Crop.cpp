#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    if (cin >> h >> w) {
        vector<string> grid(h);
        for (int i = 0; i < h; i++) {
            cin >> grid[i];
        }

        int min_r = h;
        int max_r = -1;
        int min_c = w;
        int max_c = -1;

        // Find the bounding box of the black pixels ('#')
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '#') {
                    if (i < min_r) min_r = i;
                    if (i > max_r) max_r = i;
                    if (j < min_c) min_c = j;
                    if (j > max_c) max_c = j;
                }
            }
        }

        // Print the cropped subgrid
        for (int i = min_r; i <= max_r; i++) {
            for (int j = min_c; j <= max_c; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
