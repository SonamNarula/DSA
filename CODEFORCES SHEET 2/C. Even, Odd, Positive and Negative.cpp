#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int even = 0, odd = 0;
    int pos = 0, neg = 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x % 2 == 0)
            even++;
        else
            odd++;

        if(x > 0)
            pos++;

        if(x < 0)
            neg++;
    }

    cout << "Even: " << even << '\n';
    cout << "Odd: " << odd << '\n';
    cout << "Positive: " << pos << '\n';
    cout << "Negative: " << neg << '\n';
}