class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = nums[0];

        // Maximum Kadane
        int currentMax = nums[0];
        int maxSum = nums[0];

        // Minimum Kadane
        int currentMin = nums[0];
        int minSum = nums[0];

        // Start from index 1 because nums[0]
        // is already used for initialization
        for (int i = 1; i < nums.size(); i++) {

            total += nums[i];

            // Maximum subarray
            currentMax = max(nums[i], currentMax + nums[i]);
            maxSum = max(maxSum, currentMax);

            // Minimum subarray
            currentMin = min(nums[i], currentMin + nums[i]);
            minSum = min(minSum, currentMin);
        }

        // All elements are negative
        if (maxSum < 0) {
            return maxSum;
        }

        // Circular subarray = total - minimum subarray
        return max(maxSum, total - minSum);
    }
};