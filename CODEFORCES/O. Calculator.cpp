// Given a mathematical expression. The expression will be one of the following expressions: 𝐴+𝐵
// , 𝐴−𝐵
// , 𝐴∗𝐵
//  and 𝐴/𝐵
// .

// Print the result of the mathematical expression.

// Input
// Only one line contains 𝐴,𝑆
//  and 𝐵
//  (1≤𝐴,𝐵≤104)
// , 𝑆
//  is either (+,−,∗,/)
// .

// Output
// Print the result of the mathematical expression.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    char S;

    // read A, then S, then B
    cin >> A >> S >> B;
    if (S == '+')
        cout << A + B;

    else if (S == '-')
        cout << A - B;

    else if (S == '*')
        cout << A * B;

    else if (S == '/')
        cout << A / B;
}