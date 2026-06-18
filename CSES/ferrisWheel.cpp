#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long limit;

    cin >> n >> limit;

    vector<long long> weight(n);

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    sort(weight.begin(), weight.end());

    int left = 0;
    int right = n - 1;

    int gondolas = 0;

    while (left <= right) {
        // Only one child left
        if (left == right) {
            gondolas++;
            break;
        }

        // Lightest + Heaviest fit together
        if (weight[left] + weight[right] <= limit) {
            left++;
            right--;
        }

        // Heaviest must go alone
        else {
            right--;
        }

        gondolas++;
    }

    cout << gondolas;
}