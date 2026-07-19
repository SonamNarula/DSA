#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        string s;
        cin >> s;

        // Using a flat vector as a double-ended queue to keep operations O(1)
        // with minimal overhead and contiguous cache-friendly memory.
        vector<int> dq(2 * n + 5);
        int head = n + 1;
        int tail = n;
        bool rev = false;

        for (int k = 1; k <= n; k++) {
            if (!rev) {
                dq[++tail] = k;
            } else {
                dq[--head] = k;
            }

            if (s[k - 1] == 'o') {
                rev = !rev;
            }
        }

        // Print final elements
        if (!rev) {
            for (int i = head; i <= tail; i++) {
                cout << dq[i] << (i == tail ? "" : " ");
            }
        } else {
            for (int i = tail; i >= head; i--) {
                cout << dq[i] << (i == head ? "" : " ");
            }
        }
        cout << "\n";
    }

    return 0;
}
