#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long limit;
    cin >> n >> limit;

    vector<long long> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int left = 0;
    int right = n - 1;
    int gondolas = 0;

    while (left <= right) {
        if (weights[left] + weights[right] <= limit) {
            left++;
        }

        right--;
        gondolas++;
    }

    cout << gondolas;
    return 0;
}
