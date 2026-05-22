// Given 3 numbers A, B and C, Print the minimum and the maximum numbers.

// Input
// Only one line containing 3 numbers A, B and C ( - 105 ≤ A, B, C ≤ 105)

// Output
// Print the minimum number followed by a single space then print the maximum number.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    cin >> A>>B>>C;

cout << min({A,B,C}) << " " << max({A,B,C});
}