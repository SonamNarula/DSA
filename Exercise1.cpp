// Write a program to take the marks of a student as an input,
// and output the grade.
// 0-35 : F
// 35-50 : E
// 50-60 : D
// 60-70 : C
// 70-85 : B
// 85-100 : A
// If the input is not in the range [0-100], then output it is invalid.

#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "enter marks : ";
    cin >> marks;

    if (marks > 100 || marks < 0) {
        cout << "Invalid";
    } else if (marks >= 0 && marks <= 35) {
        cout << "F grade";
    }

    else if (marks >= 35 && marks <= 50) {
        cout << "E grade";
    } else if (marks >= 50 && marks <= 60) {
        cout << "D grade";
    }

    else if (marks >= 60 && marks <= 70) {
        cout << "C grade";

    }

    else if (marks >= 70 && marks <= 85) {
        cout << "B grade";
    } else
        cout << "A grade";
}
