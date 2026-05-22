// Given a number 𝑁
// . Determine whether 𝑁
//  is float number or integer number.

// Note:

// If 𝑁
//  is float number then print "float" followed by the integer part followed by decimal part separated by space.
// If 𝑁
//  is integer number then print "int" followed by the integer part separated by space.
// For more clarification see the examples below.

// Input
// Only one line containing a number 𝑁
//  (1≤𝑁≤103)

// Output
// Print the answer required above.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    double N;
    cin >> N;

    int integerPart = N;
    double decimalPart = N - integerPart;

    if(decimalPart == 0)
        cout << "int " << integerPart;
    else
        cout << "float " << integerPart << " " << decimalPart;

    return 0;
}
