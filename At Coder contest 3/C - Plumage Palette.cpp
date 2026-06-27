#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (cin >> n >> m) {
        vector<int> a(n);
        vector<int> d(n);
        vector<int> b(n);

        vector<vector<int>> events(m + 1);
        vector<int> freq(n + 1, 0);
        int unique_colors = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i] >> d[i] >> b[i];

            int initial_color;
            if (d[i] == 1) {
                initial_color = b[i];
            } else {
                initial_color = a[i];
                if (a[i] != b[i]) {
                    events[d[i]].push_back(i);
                }
            }

            freq[initial_color]++;
            if (freq[initial_color] == 1) {
                unique_colors++;
            }
        }

        for (int j = 1; j <= m; j++) {
            if (j > 1) {
                for (int idx : events[j]) {
                    int old_color = a[idx];
                    int new_color = b[idx];

                    freq[old_color]--;
                    if (freq[old_color] == 0) {
                        unique_colors--;
                    }

                    freq[new_color]++;
                    if (freq[new_color] == 1) {
                        unique_colors++;
                    }
                }
            }
            cout << unique_colors << "\n";
        }
    }

    return 0;
}
