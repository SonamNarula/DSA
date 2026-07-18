class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int left = 0, right = n - 1;
        long long cnt = 0;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum < target) {
                left++;
            }
            else if (sum > target) {
                right--;
            }
            else {
                // If both values are same
                if (arr[left] == arr[right]) {
                    long long k = right - left + 1;
                    cnt += (k * (k - 1)) / 2;
                    break;
                }

                long long leftCount = 1, rightCount = 1;

                while (left + 1 < right && arr[left] == arr[left + 1]) {
                    leftCount++;
                    left++;
                }

                while (right - 1 > left && arr[right] == arr[right - 1]) {
                    rightCount++;
                    right--;
                }

                cnt += leftCount * rightCount;
                left++;
                right--;
            }
        }

        return cnt;
    }
};