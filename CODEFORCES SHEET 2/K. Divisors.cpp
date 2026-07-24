// =========APPROACH 1==========

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl '\n'

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     for (int i = 1; i <= n; i++) {
//         if (n % i == 0) {
//             cout << i << endl;
//         }
//     }

//     return 0;
// }

// =========APPROACH 2==========
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> divisors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);

            if (i != n / i)
                divisors.push_back(n / i);
        }
    }

    sort(divisors.begin(), divisors.end());

    for (int x : divisors)
        cout << x << endl;

    return 0;
}