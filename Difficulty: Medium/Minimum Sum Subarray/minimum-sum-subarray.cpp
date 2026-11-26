class Solution {
public:
    int minSubarraySum(vector<int>& arr) {
        int n = arr.size();

        // Minimum sum of a subarray that
        // ends exactly at the current index
        int bestEnding = arr[0];

        // Minimum sum found anywhere in the array
        int ans = arr[0];

        // arr[0] is already considered,
        // so start from index 1
        for (int i = 1; i < n; i++) {

            // Option 1:
            // Extend the previous minimum-sum subarray
            int v1 = bestEnding + arr[i];

            // Option 2:
            // Start a new subarray from the current element
            int v2 = arr[i];

            // Choose the smaller sum
            bestEnding = min(v1, v2);

            // Update the overall minimum sum
            ans = min(ans, bestEnding);
        }

        return ans;
    }
};