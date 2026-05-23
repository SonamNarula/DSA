// A. Slimes on a Line
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// There are 𝑛 slimes on a line, where slime 𝑖 is at position 𝑎𝑖 on the line. You will perform the following operation some number of times (possibly none):

// * select an integer 𝑥, then for each 𝑗 (1≤𝑗≤𝑛):
//    * if 𝑎𝑗<𝑥 then do 𝑎𝑗:=𝑎𝑗+1.
//    * if 𝑎𝑗>𝑥 then do 𝑎𝑗:=𝑎𝑗−1.
//    * if 𝑎𝑗=𝑥 then do nothing.
// Determine the minimum number of operations to make all slimes occupy the same position.
// Input
// Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤100). The description of the test cases follows.
// The first line of each testcase contains an integer 𝑛 (2≤𝑛≤1000) — the number of slimes.
// The second line of each testcase contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤1000) — the initial positions of the slimes.
// It is guaranteed that the sum of 𝑛 over all test cases does not exceed 1000.
// Output
// For each testcase, output the minimum number of operations required to make all slimes occupy the same position.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int mn = 1e9, mx = -1e9;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            mn = min(mn, x);
            mx = max(mx, x);
        }

        cout << (mx - mn + 1) / 2 << '\n';
    }

    return 0;
}