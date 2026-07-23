#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n;
    long long target;
    cin >> n >> target;

    vector<pair<long long, int>> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i].first;
        values[i].second = i + 1;
    }

    sort(values.begin(), values.end());

    for (int i = 0; i < n; i++) {
        int left = i + 1;
        int right = n - 1;
        long long needed = target - values[i].first;

        while (left < right) {
            long long sum = values[left].first + values[right].first;

            if (sum == needed) {
                cout << values[i].second << ' '
                     << values[left].second << ' '
                     << values[right].second;
                return 0;
            }

            if (sum < needed) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
