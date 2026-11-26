// Given 4 numbers 𝐴,𝐵,𝐶
//  and 𝐷
// . If 𝐴𝐵
//  > 𝐶𝐷
//  print "YES" otherwise, print "NO".

// Input
// Only one line containing 4 numbers 𝐴,𝐵,𝐶
//  and 𝐷
//  (1≤𝐴,𝐶≤107)
//  , (1≤𝐵,𝐷≤1012)

// Output
// Print "YES" or "NO" according to the problem above.

#include <bits/stdc++.h>
using namespace std;

int main() {

    double A, B, C, D;
    cin >> A >> B >> C >> D;

    // Compare A^B and C^D using logarithm
    if (B * log(A) > D * log(C))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}