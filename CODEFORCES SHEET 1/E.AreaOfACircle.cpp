// Given a number R calculate the area of a circle using the following formula:

// Area = π * R2.

// Note: consider π = 3.141592653.

// Input
// Only one line containing the number R (1  ≤  R  ≤  100).

// Output
// Print the calculated area, with 9 digits after the decimal point.

#include <bits/stdc++.h>
using namespace std;

int main() {
    double R;
    cin >> R;

    double pi = 3.141592653;

    cout << fixed << setprecision(9) << pi * R * R ;
}