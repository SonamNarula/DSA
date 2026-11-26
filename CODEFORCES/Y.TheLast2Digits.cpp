#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    long long result = (A % 100) * (B % 100) * (C % 100) * (D % 100);
    result %= 100;
    cout << result;
}