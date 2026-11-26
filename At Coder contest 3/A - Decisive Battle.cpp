#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        int e = 0, w = 0;
        for (char c : s) {
            if (c == 'E') {
                e++;
            } else if (c == 'W') {
                w++;
            }
        }

        if (e > w) {
            cout << "East\n";
        } else {
            cout << "West\n";
        }
    }

    return 0;
}
