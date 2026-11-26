// Given a mathematical expression. The expression will be one of the following expressions:

// A + B = C, A - B = C and A * B = C

// where A, B, C are three numbers, S is the sign between A and B, and Q the '=' sign

// Print "Yes" If the expression is Right , Otherwise print the right answer of the expression.

// Input
// Only one line containing the expression: A, S, B, Q, C respectively (0 ≤ A, B ≤ 100,  - 105 ≤ C ≤ 105) and S can be ('+', '-', '*') without the quotation.

// Output
// Output either "Yes" (without the quotation) or the right answer depending on the statement.

#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    char S, Q;

    cin >> A >> S >> B >> Q >> C;

    int result;

    if (S == '+') {
        result = A + B;
    }
    else if (S == '-') {
        result = A - B;
    }
    else {
        result = A * B;
    }

    if (result == C) {
        cout << "Yes";
    }
    else {
        cout << result;
    }

    return 0;
}