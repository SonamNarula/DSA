class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int maxEnding = arr[0];
        int minEnding = arr[0];
        int maxSum = arr[0];
        int minSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            // Best positive-sum subarray ending here.
            maxEnding = max(arr[i], maxEnding + arr[i]);
            maxSum = max(maxSum, maxEnding);
            // Best negative-sum subarray ending here.
            minEnding = min(arr[i], minEnding + arr[i]);
            minSum = min(minSum, minEnding);
        }
        return max(maxSum, -minSum);
    }
};