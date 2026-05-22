// Given 4 numbers 𝐴
// , 𝐵
// , 𝐶
//  and 𝐷
// . Print the last 2 digits from their Multiplication.

// Input
// Only one line containing four numbers 𝐴
// , 𝐵
// , 𝐶
//  and 𝐷
//  (2≤𝐴,𝐵,𝐶,𝐷≤109)
// .

// Output
// Print the last 2 digits from their Multiplication.

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    long long result = (A % 100) * (B % 100) * (C % 100) * (D % 100);
    result %= 100;
    cout << result;
}