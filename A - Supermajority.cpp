#include <iostream>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    if (cin >> a >> b) {
        // We need to check if A > B * (2/3)
        // Multiplying both sides by 3 to avoid floating-point issues:
        // 3 * A > 2 * B
        if (3 * a > 2 * b) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
