#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    long long targetSum;

    cin >> n >> targetSum;

    // {value, original index}
    vector<pair<long long, int>> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    sort(nums.begin(), nums.end());

    // Fix first number
    for (int i = 0; i < n; i++) {

        long long requiredSum = targetSum - nums[i].first;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            long long currentSum =
                nums[left].first + nums[right].first;

            if (currentSum == requiredSum) {

                cout << nums[i].second << " "
                     << nums[left].second << " "
                     << nums[right].second;

                return 0;
            }

            else if (currentSum < requiredSum) {
                left++;
            }

            else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}