// Given a number 𝑁
// . Print the summation of the numbers that is between 1 and 𝑁
//  (inclusive).

// .∑𝑖=1𝑁𝑖
// Input
// Only one line containing a number 𝑁
//  (1≤𝑁≤109)

// Output
// Print the summation of the numbers that are between 1 and 𝑁
//  (inclusive).

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;

    cout << (N * (N + 1)) / 2 << endl;
}