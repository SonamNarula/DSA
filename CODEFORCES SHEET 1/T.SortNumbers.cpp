#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int x = A, y = B, z = C;

    if (x > y) {
        swap(x, y);
    }

    if (x > z) {
        swap(x, z);
    }

    if (y > z) {
        swap(y, z);
    }

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    cout << endl;

    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
}
