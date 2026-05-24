// C2. We Be Flipping (Hard Version)
// time limit per test2 seconds
// memory limit per test256 megabytes

// This is the hard version of the problem. The difference between the versions is that in this version, you must maximise the sum. You can hack only if you solved all versions of this problem.

// You have an array 𝑎
//  of length 𝑛
//  which consists of non-zero (but possibly negative) integers. You will perform the following operation at most 𝑛
//  times (possibly none):

// select an index 𝑖
//  (1≤𝑖≤𝑛
// ) such that 𝑎𝑖>0
// then for each 𝑗
//  where 1≤𝑗≤𝑖
//  do 𝑎𝑗:=−𝑎𝑗
// .
// Output a valid sequence of operations of length at most 𝑛
//  which maximises
//  the sum of 𝑎
//  at the end.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases 𝑡
//  (1≤𝑡≤104
// ). The description of the test cases follows.

// The first line of each testcase contains an integer 𝑛
//  (2≤𝑛≤2⋅105
// ) — the length of the array 𝑎
// .

// The second line of each testcase contains 𝑛
//  integers 𝑎1,𝑎2,…,𝑎𝑛
//  (−109≤𝑎𝑖≤109,𝑎𝑖≠0
// ).

// It is guaranteed that the sum of 𝑛
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each testcase, output a single integer 𝑘
//  (0≤𝑘≤𝑛
// ) — the number of operations you will perform.

// Now output 𝑘
//  integers 𝑏1,…,𝑏𝑘
//  where 𝑏𝑖
//  is the index you perform the 𝑖
// th operation on.

// After performing the operations the sum of 𝑎
//  should be maximal.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        vector<ll> a(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> ops;

        int parity = 0;

        for (int i = n; i >= 1; i--) {

            ll cur = (parity ? -a[i] : a[i]);

            if (cur < 0) {
                ops.push_back(i);
                parity ^= 1;
            }
        }

        cout << ops.size() << '\n';

        for (int x : ops)
            cout << x << ' ';

        cout << '\n';
    }

    return 0;
}