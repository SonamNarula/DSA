#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k, a;
    cin >> n >> k >> a;

    __int128 p = (__int128)n * k;

    if (p % a != 0) {
        cout << "double";
    }
    else {
        p /= a;

        if (p <= INT_MAX)
            cout << "int";
        else
            cout << "long long";
    }

    return 0;
}