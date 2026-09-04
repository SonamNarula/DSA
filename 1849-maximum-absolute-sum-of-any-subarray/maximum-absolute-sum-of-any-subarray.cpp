class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        // Maximum subarray sum
        int maxEnding = 0;
        int maxSoFar = 0;

        // Minimum subarray sum
        int minEnding = 0;
        int minSoFar = 0;

        for (int x : nums) {

            // -------------------------------
            // Kadane for MAXIMUM subarray sum
            // -------------------------------

            // Either:
            // 1. Start a new subarray from x
            // 2. Extend the previous subarray
            maxEnding = max(0, maxEnding + x);

            // Store the maximum sum found so far
            maxSoFar = max(maxSoFar, maxEnding);


            // -------------------------------
            // Kadane for MINIMUM subarray sum
            // -------------------------------

            // Either:
            // 1. Start a new subarray from x
            // 2. Extend the previous subarray
            minEnding = min(0, minEnding + x);

            // Store the minimum (most negative) sum
            minSoFar = min(minSoFar, minEnding);
        }

        // Maximum absolute sum can come from:
        //
        // 1. Maximum positive subarray sum
        // 2. Absolute value of minimum negative subarray sum
        //
        // Example:
        // maxSoFar = 5
        // minSoFar = -8
        // answer = max(5, 8) = 8

        return max(maxSoFar, abs(minSoFar));
    }
};