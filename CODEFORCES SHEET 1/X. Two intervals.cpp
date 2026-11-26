// Given the boundaries of 2 intervals. Print the boundaries of their intersection.

// Note: Boundaries mean the two ends of an interval which are the starting number and the ending number.

// Input
// Only one line contains two intervals [𝑙1,𝑟1]
// , [𝑙2,𝑟2]
//  where (1≤𝑙1,𝑙2,𝑟1,𝑟2≤109)
// , (𝑙1≤𝑟1,𝑙2≤𝑟2)
// .

// It's guaranteed that 𝑙1≤𝑟1
//  and 𝑙2≤𝑟2
// .

// Output
// If there is an intersection between these 2 intervals print its boundaries , otherwise print -1.

#include <iostream>
using namespace std;

int main() {

    long long l1, r1, l2, r2;

    cin >> l1 >> r1 >> l2 >> r2;

    long long left = max(l1, l2);
    long long right = min(r1, r2);

    if (left <= right) {
        cout << left << " " << right;
    }
    else {
        cout << -1;
    }

    return 0;
}