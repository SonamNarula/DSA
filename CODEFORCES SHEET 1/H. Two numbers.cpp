// Given 2 numbers 𝐴
//  and 𝐵
// . Print floor, ceil and round of 𝐴/𝐵

// Note:

// Floor: Is a mathematical function that takes a real number 𝑋
//  and its output is the greatest integer less than or equal to 𝑋
// .
// Ceil: Is a mathematical function that takes a real number 𝑋
//  and its output is the smallest integer larger than or equal to 𝑋
// .
// Round: Is a mathematical function that takes a real number 𝑋
//  and its output is the closest integer to that number 𝑋
// .Input
// Only one line containing two numbers 𝐴
//  and 𝐵
//  (1≤𝐴,𝐵≤103)

// Output
// Print 3 lines that contain the following in the same order:

// "floor 𝐴
//  / 𝐵
//  = Floor result" without quotes.
// "ceil 𝐴
//  / 𝐵
//  = Ceil result" without quotes.
// "round 𝐴
//  / 𝐵
//  = Round result" without quotes.

#include <bits/stdc++.h>
using namespace std;

int main() {
    double num1, num2;
    cin >> num1 >> num2;
    double re = num1 / num2;
    cout << "floor " << num1 << " / " << num2 << " = " << floor(re) << endl;
    cout << "ceil " << num1 << " / " << num2 << " = " << ceil(re) << endl;
    cout << "round " << num1 << " / " << num2 << " = " << round(re) << endl;
}