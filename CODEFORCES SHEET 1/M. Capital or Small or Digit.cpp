// Given a letter X. Determine whether X is Digit or Alphabet and if it is Alphabet determine if it
// is Capital Case or Small Case.

// Note:

// Digits in ASCII '0' = 48,'1' = 49 ....etc
// Capital letters in ASCII 'A' = 65, 'B' = 66 ....etc
// Small letters in ASCII 'a' = 97,'b' = 98 ....etc
// Input
// Only one line containing a character X which will be a capital or small letter or digit.

// Output
// Print a single line contains "IS DIGIT" if X is digit otherwise, print "ALPHA" in the first line
// followed by a new line that contains "IS CAPITAL" if X is a capital letter and "IS SMALL" if X is
// a small letter.

#include <bits/stdc++.h>
using namespace std;

int main() {
    char X;
    cin >> X;

    // if (X >= '0' && X <= '9') {
    //     cout << "IS DIGIT" << endl;
    // } else if (X >= 'A' && X <= 'Z') {
    //     cout << "ALPHA" << endl;
    //     cout << "IS CAPITAL" << endl;
    // } else if (X >= 'a' && X <= 'z') {
    //     cout << "ALPHA" << endl;
    //     cout << "IS SMALL" << endl;
    // }

    if (X >= 48 && X <= 57) {
        cout << "IS DIGIT" << endl;
    }
    // Check if X is an alphabet
    else {
        cout << "ALPHA" << endl;

        // Check if X is capital using ASCII values (65 to 90)
        if (X >= 65 && X <= 90) {
            cout << "IS CAPITAL" << endl;
        }
        // Check if X is small using ASCII values (97 to 122)
        else if (X >= 97 && X <= 122) {
            cout << "IS SMALL" << endl;
        }
    }
}